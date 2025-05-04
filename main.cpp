#include <iostream>
#include <cctype>
#include <fstream>
#include <filesystem>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "wrong number of arguments!" << endl;
        return 1;
    }

    int k = stoi(argv[1]); // number of lists to merge
    string inputPath = argv[2]; // 
    string outputPath = argv[3];

    int num = 0;
    int i = 0;

    vector<vector<int>> arrays;

    for(const auto& entry : filesystem::directory_iterator(inputPath)){
        if(entry.is_regular_file()){
            if(i >= k) break;
            ifstream inputFile;
            inputFile.open(entry.path());  

            if(inputFile.fail()){
                cout << "error while opening the file!" << endl;
                return 1;
            }

            vector<int> numberArr;
            string line;

            while(getline(inputFile, line)){
                int number = stoi(line);
                numberArr.push_back(number);
            }   
            arrays.push_back(numberArr);
            inputFile.close();
        }
        i++;
    }
    for (int i = 0; i < arrays.size(); i++) {
        for (int num : arrays[i]) {
            cout << num << " ";
        }
        cout << endl;
        cout << "-- (" << i << ".txt) --" << endl;
    }

    return 0;
}