#include <iostream>
#include <cctype>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <vector>
#include <cmath>
#include <chrono>
#include <queue>

using namespace std;

class MinHeapElement{
    private:
        int arrayIndex;
        int elemIndex;
        int value;
    public:
        MinHeapElement(int value, int arrayIndex, int elemIndex);
        int getArrayIndex(){ 
            return this->arrayIndex; 
        };

        int getElemIndex(){ 
            return this->elemIndex; 
        };

        int getValue(){ 
            return this->value; 
        };

        bool operator<(const MinHeapElement& other) const{
            return this->value > other.value;
        }
};

MinHeapElement::MinHeapElement(int value, int arrayIndex, int elemIndex){
    this->value = value;
    this->arrayIndex = arrayIndex;
    this->elemIndex = elemIndex;
}

vector<int> mergeKArrays(vector<vector<int>>& arrays){
    vector<int> result;
    priority_queue<MinHeapElement> minHeap;

    for(int i = 0; i < arrays.size(); i++){
        minHeap.push(MinHeapElement(arrays[i][0], i, 0)); // insert the first (smallest) element of an array into the minHeap
    }

    while(!minHeap.empty()){
        MinHeapElement element = minHeap.top();
        // what I need to remember:
        // which array did the number came from (array index)
        // what number was it (value)
        // where was the number in the array (element index)
        int value = element.getValue();
        int arrayIndex = element.getArrayIndex();
        int elemIndex = element.getElemIndex();

        result.push_back(value);
        minHeap.pop();
        if(elemIndex + 1 < arrays[arrayIndex].size()){
            int nextValue = arrays[arrayIndex][elemIndex++];
            minHeap.push(MinHeapElement(nextValue, arrayIndex, elemIndex++));
        }
    }
    return result;
}

vector<vector<int>> browseFiles(int arrNum, string inputPath, int filesNum){
    vector<vector<int>> finalArray;
    int fileIndex = 0;

    if(arrNum > filesNum){
        cout << "input number is way too large!" << endl << "number of files in directory: " << filesNum << endl;
        exit(1);
    }

    for(const auto& entry : filesystem::directory_iterator(inputPath)){
        if(entry.is_regular_file()){
            if(fileIndex >= arrNum){
                break;
            }
            ifstream inputFile;
            inputFile.open(entry.path());  

            if(inputFile.fail()){
                cout << "error while opening the file!" << endl;
                exit(1);
            }
            vector<int> numberArr;
            string line;
            cout << entry << endl;
            while(getline(inputFile, line)){
                int number = stoi(line);
                numberArr.push_back(number);
            }   
            finalArray.push_back(numberArr);
            inputFile.close();
        }
        fileIndex++;
    }
    return finalArray;
}

void putToOutFile(string outputPath, vector<int> arr){
    ofstream outputFile;
    outputFile.open(outputPath);

    if(outputFile.fail()){
        cout << "error while writing to file!" << endl;
        exit(1);
    }    

    for(int num : arr){
        outputFile << num << endl;
    }

    outputFile.close();
}

// returns number of files in the folder
int getFilesNum(string directory){
    int filesNum = 0;
    for(const auto& entry : filesystem::directory_iterator(directory)){
        if(entry.is_regular_file()){
            filesNum++;
        }
    }
    return filesNum;
}


// need to add a file sorting function
int main(int argc, char* argv[]){
    auto startTime = chrono::high_resolution_clock::now();

    if(argc != 4){
        cout << "wrong number of arguments!" << endl;
        return 1;
    }

    int k = stoi(argv[1]); // number of lists to merge
    string inputPath = argv[2]; 
    string outputPath = argv[3];
    int num = 0;

    // check if the input file exists
    if(!filesystem::exists(inputPath) || !filesystem::is_directory(inputPath)){
        cout << "input directory does not exist!" << endl;
        exit(1);
    }

    int filesNum = getFilesNum(inputPath);


    vector<vector<int>> arrays = browseFiles(k, inputPath, filesNum);
    vector<int> mergedArr = mergeKArrays(arrays);
    putToOutFile(outputPath, mergedArr);
    
    auto endTime = chrono::high_resolution_clock::now();

    auto elapsedTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);

    cout << "program took: " << elapsedTime.count() << " ms" << endl;

    return 0;
}
