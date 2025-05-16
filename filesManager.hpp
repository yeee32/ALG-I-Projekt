#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Writes an array of integers to an output file.
 *
 * @param outputPath Path to the output file.
 * @param arr Vector of integers to write to the file.
 */
void putToOutFile(string outputPath, vector<int> arr);

/**
 * @brief Counts the number of regular files in a directory.
 *  
 * @param directory Path of the directory.
 * @return Number of files in the directory.
 */
int getFilesNum(string directory);

/**
 * @brief Checks the existence of the input path.
 * 
 * @param inputPath Path to check for validity.
 */
void inputFileCheck(string inputPath);


/**
 * @brief Sorts the filenames in the given input directory in alphabetical order.
 *  
 * @param inputDirectoryPath The path to the directory containing the files.
 * @return A vector of sorted filenames as strings.
 */
vector<string> sortFiles(string inputDirectoryPath);
