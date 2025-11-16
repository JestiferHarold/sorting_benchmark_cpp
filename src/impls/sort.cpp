#include <iostream>
#include <vector>
#include "../header/sort.hpp"

using namespace std;

Sorting::Sorting(vector<int> &vec) {
    this->unsorted_array = vec;
}

void Sorting::set_unsorted_array(vector<int> vec) {
    this->unsorted_array = vec;
}

NumberOfComparisons Sorting::get_comparisons() {
    return this->comparisons;
}

NumberOfSwaps Sorting::get_swaps() {
    return this->swaps;
}

bool Sorting::check_sortedness() {
    if (unsorted_array.size() != sorted_array.size()) {
        cout << "Sorted array has missing elements" << "\n";
        return false;
    }

    if (sorted_array.size() == 0) {
        return true;
    }

    int min = 0;

    for (int i = 1; i < sorted_array.size() - 1; i ++, min = i - 1) {
        if (sorted_array[min] > sorted_array[i]) {
            cout << "Array is not sorted properly" << "\n";
            return false;
        }
    }

    return true;
}

void Sorting::print_sorted() {
    for (auto a: sorted_array) {
        cout << a << "\t";
    }
}

void Sorting::print_unsorted() {
    for (auto a: unsorted_array) {
        cout << a << "\t";
    }
}

void Sorting::bubble_sort() {
    vector<int> array = unsorted_array;
    bool swapped;
    int swaps = 0;
    int comparisons = 0;

    for (int i = 0; i < array.size() - 1; i ++) {
        swapped = false;
        for (int j = 0; j < array.size() - i - 1; j ++) {
            comparisons ++;
            if (array[j + 1] < array[j]){
                swap(array[j + 1], array[j]);
                swapped = true;
                swaps ++;
            }
        }

        if (!swapped) break;
    }

    sorted_array = array;

    this->swaps = swaps;
    this->comparisons = comparisons;
}

void Sorting::selection_sort() {
    vector<int> array = unsorted_array;
    int min;
    int swaps = 0;
    int comparisons = 0;

    for (int i = 0; i < array.size(); i ++) {
        min = i;
        for (int j = i; j < array.size(); j ++) {
            comparisons ++;
            if (array[min] > array[j]) {
                min = j;
            }
        }

        swaps ++;
        swap(array[min], array[i]);
    }

    sorted_array = array;
    this->comparisons = comparisons;
    this->swaps = swaps;
}

void Sorting::insertion_sort() {
    vector<int> array = unsorted_array;
    int j;
    int swaps = 0;
    int comparisons = 0;

    for (int i = 1; i < array.size(); i ++) {
        j = i;
        
        while (j > 0 && array[j] < array[j - 1]) {
            swaps++;
            comparisons++;
            swap(array[j], array[j - 1]);
            j --;
        }

    }

    sorted_array = array;
}