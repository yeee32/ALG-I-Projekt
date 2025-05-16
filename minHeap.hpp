#pragma once
#include <iostream>

using namespace std;

/**
 * @brief Represents an element in a min-heap with tracking information.
 */
class MinHeapElement {
private:
    int arrayIndex;  ///< Index of the array of the element.
    int elemIndex;   ///< Index of the element in the array.
    int value;       ///< The value of the element.

public:
    /**
     * @brief Constructs for MinHeapElemnt class
     * 
     * @param value       The current integer value.
     * @param arrayIndex  Index of the original array.
     * @param elemIndex   Index of the element in it's array.
     */
    MinHeapElement(int value, int arrayIndex, int elemIndex);

    /**
     * @brief Gets the array index of the ele,emt.
     * @return The array index.
     */
    int getArrayIndex() { return this->arrayIndex; }

    /**
     * @brief Gets the index of this element in it's original array.
     * @return The element index.
     */
    int getElemIndex() { return this->elemIndex; }

    /**
     * @brief Gets the value of the element.
     * @return The integer value.
     */
    int getValue() { return this->value; }

    /**
     * @brief Compares two MinHeapElements based on value for min-heap ordering.
     * 
     * This is used by the priority queue to maintain a min-heap.
     * If the other value is greater than current value, it has lower priority
     * so the smaller numbers have higher priority.
     * 
     * @param other The other element to compare with.
     * @return True if this element is greater than the other (min-heap logic).
     */
    bool operator<(const MinHeapElement& other) const {
        return this->value > other.value;
    }
};
