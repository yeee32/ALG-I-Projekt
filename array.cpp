#include "array.hpp"

vector<vector<int>> makeArrays(int arrNum, string inputPath, int filesNum){
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
            // cout << entry << endl;
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

vector<int> mergeKArrays(vector<vector<int>>& arrays){
    vector<int> mergedArr;
    priority_queue<MinHeapElement> minHeap;

    for(size_t i = 0; i < arrays.size(); i++){
        minHeap.push(MinHeapElement(arrays[i][0], i, 0)); // insert the first (smallest) element of an array into the minHeap
    }

    while(!minHeap.empty()){
        MinHeapElement element = minHeap.top();
        // what I need to remember:
        // which array did the number came from (array index)
        // what number was it (value)
        // where was the number in the array (element index)
        size_t value = element.getValue();
        size_t arrayIndex = element.getArrayIndex();
        size_t elemIndex = element.getElemIndex();

        mergedArr.push_back(value);
        minHeap.pop();
        if(elemIndex + 1 < arrays[arrayIndex].size()){
            int nextValue = arrays[arrayIndex][elemIndex + 1];
            minHeap.push(MinHeapElement(nextValue, arrayIndex, elemIndex + 1));
        }
    }
    return mergedArr;
}