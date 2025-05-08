#include "minHeap.hpp"

MinHeapElement::MinHeapElement(int value, int arrayIndex, int elemIndex){
    this->value = value;
    this->arrayIndex = arrayIndex;
    this->elemIndex = elemIndex;
}