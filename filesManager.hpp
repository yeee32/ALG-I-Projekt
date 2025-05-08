#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

using namespace std;

void putToOutFile(string outputPath, vector<int> arr);
int getFilesNum(string directory);
void inputFileCheck(string inputPath);