#pragma once
#include "filesManager.hpp"
#include "minHeap.hpp"
#include <queue> 

vector<vector<int>> makeArrays(int arrNum, string inputPath, int filesNum);
vector<int> mergeKArrays(vector<vector<int>>& arrays);