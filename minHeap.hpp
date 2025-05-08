#pragma once
#include <iostream>

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