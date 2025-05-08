#include <chrono>
#include "filesManager.hpp"
#include "minHeap.hpp"
#include "array.hpp"

int main(int argc, char* argv[]){
    auto startTime = chrono::high_resolution_clock::now();

    if(argc != 4){
        cout << "wrong number of arguments!" << endl;
        return 1;
    }

    int k = stoi(argv[1]); // number of lists to merge
    string inputPath = argv[2]; 
    string outputPath = argv[3];

    // check if the input file exists
    inputFileCheck(inputPath);

    int filesNum = getFilesNum(inputPath);

    vector<vector<int>> arrays = makeArrays(k, inputPath, filesNum);
    vector<int> mergedArr = mergeKArrays(arrays);
    putToOutFile(outputPath, mergedArr);
    
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
    
    cout << k << " arrays succesfully merged!" << endl;
    cout << "Program took: " << elapsedTime.count() << " ms" << endl;

    return 0;
}
