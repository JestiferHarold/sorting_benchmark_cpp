#include <iostream>
#include <vector>
#include "sort.cpp"

void Sorting::bubble_sort() {
    vector<int> array = this->unsorted_array;
    int size = array.size();

    for (int i = 0; i < size; i ++) {
        bool swapped = false;
        int min_val_index = i;

        for (int j = i; j < size; j ++) {
            if (array[min_val_index] > array[j]) {
                min_val_index = j;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }

        swap(array[i], array[min_val_index]);
    }

    this->sorted_array = array;
}