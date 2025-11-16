#include <iostream>
#include <vector>
#include "../header/sort.hpp"

using namespace std;

Sorting::Sorting(vector<int> &vec) {
    this->unsorted_array = vec;
}

void Sorting::check_sortedness() {
    if (unsorted_array.size() != sorted_array.size()) {
        cout << "Sorted array has missing elements" << "\n";
        return;
    }

    if (sorted_array.size() == 0) {
        cout << "Array is sorted" << "\n";
        return;
    }

    int min = 0;

    for (int i = 1; i < sorted_array.size() - 1; i ++, min = i - 1) {
        if (sorted_array[min] > sorted_array[i]) {
            cout << "Array is not sorted properly" << "\n";
            return;
        }
    }

    cout << "Array is sorted well" << "\n";
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

    for (int i = 0; i < array.size() - 1; i ++) {
        swapped = false;
        for (int j = 0; j < array.size() - i - 1; j ++) {
            if (array[j + 1] < array[j]){
                swap(array[j + 1], array[j]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }

    sorted_array = array;
}

void Sorting::selection_sort() {
    vector<int> array = unsorted_array;
    int min;
    for (int i = 0; i < array.size(); i ++) {
        min = i;
        for (int j = i; j < array.size(); j ++) {
            if (array[min] > array[j]) {
                min = j;
            }
        }

        swap(array[min], array[i]);
    }

    sorted_array = array;
}