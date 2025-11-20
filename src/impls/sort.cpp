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

vector<int> Sorting::get_sorted_array() {
    return this->sorted_array;
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
    long long swaps = 0;
    long long comparisons = 0;

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
    long long swaps = 0;
    long long comparisons = 0;

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
    int j, key;
    long long swaps = 0;
    long long comparisons = 0;

    for (int i = 1; i < array.size(); i ++) {
        j = i - 1; 
        key = array[i];
        
        while (j >= 0 && array[j] > key) {
            array[j + 1]  = array[j];
            j --, comparisons ++, swaps ++;
        }

        array[j + 1] = key;
        swaps ++;
    }

    sorted_array = array;
    this->swaps = swaps;
    this->comparisons = comparisons;
}

void Sorting::merge_helper(vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i ++) {
        L[i] = array[left + i];
    }

    for (int j = 0; j < n2; j ++) {
        R[j] = array[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        this->comparisons ++;
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i ++, this->swaps ++;
        } else {
            array[k] = R[j];
            j ++, this->swaps ++;
        }
        k ++;
    }

    while (i < n1) {
        array[k] = L[i];
        i ++, k ++, this->swaps ++;
    }

    while (j < n2) {
        array[k] = R[j];
        j ++, k ++, this->swaps ++;
    }
}

void Sorting::merge(vector<int>& array, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    merge(array, left, mid);
    merge(array, mid + 1, right);
    merge_helper(array, left, mid, right);
}

void Sorting::merge_sort() {
    vector<int> array = this->unsorted_array;
    this->swaps = this->comparisons = 0;
    merge(array, 0, array.size() - 1);
    this->sorted_array = array;
}

int Sorting::partition(vector<int>& array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j ++) {
        this->comparisons ++;
        if (array[j] < pivot) {
            i ++;
            swap(array[i], array[j]);
            this->swaps ++;
        }
    }

    swap(array[i + 1], array[high]);
    this->swaps ++;
    return i + 1;
}

void Sorting::quick_helper(vector<int>& array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_helper(array, low, pi - 1);
        quick_helper(array, pi + 1, high);
    }
}

void Sorting::quick_sort() {
    vector<int> array = this->unsorted_array;
    this->comparisons = this->swaps = 0;
    quick_helper(array, 0, array.size() - 1);
    this->sorted_array = array;
}
