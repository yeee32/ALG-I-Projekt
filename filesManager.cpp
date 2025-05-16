#include "filesManager.hpp"

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

int getFilesNum(string directory){
    int filesNum = 0;
    for(const auto& entry : filesystem::directory_iterator(directory)){
        if(entry.is_regular_file()){
            filesNum++;
        }
    }
    return filesNum;
}

void inputFileCheck(string inputPath){
    if(!filesystem::exists(inputPath) || !filesystem::is_directory(inputPath)){
        cout << "input directory does not exist!" << endl;
        exit(1);
    }
}

vector<string> sortFiles(string inputDirectoryPath){
    vector<string> folders;
    for(const auto& entry : filesystem::directory_iterator(inputDirectoryPath)){
        if(entry.is_regular_file()){
            folders.push_back(entry.path());
        }
    } 
    sort(folders.begin(), folders.end());
    return folders;
}
