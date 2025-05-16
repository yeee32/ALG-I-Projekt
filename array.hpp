#pragma once
#include "filesManager.hpp"
#include "minHeap.hpp"
#include <queue> 

/**
 * @brief Creates arrays from input files.
 * 
 * @param arrNum     Number of arrays to create.
 * @param inputPath  Path to the input folder.
 * @param filesNum   Number of files in the folder.
 * @return A vector of int vectors, each containing data from one file.
 */
vector<vector<int>> makeArrays(int arrNum, string inputPath, int filesNum);

/**
 * @brief Merges multiple sorted arrays into a single sorted array.
 * 
 * The algorithm was inspired by: https://www.youtube.com/watch?v=ptYUCjfNhJY
 * and https://en.wikipedia.org/wiki/Merge_algorithm
 * @param arrays A reference to a vector of sorted int arrays.
 * @return A merged array of all the input arrays.
 */
vector<int> mergeKArrays(vector<vector<int>>& arrays);
