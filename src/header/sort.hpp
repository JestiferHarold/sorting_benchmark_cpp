#pragma once

#include <vector>

typedef long long NumberOfSwaps;
typedef long long NumberOfComparisons;

class Sorting {
    private:
        std::vector<int> unsorted_array;
        std::vector<int> sorted_array;
        NumberOfSwaps swaps;
        NumberOfComparisons comparisons;
        void merge_helper(std::vector<int>& array, int left, int mid, int right);
        void merge(std::vector<int>& array, int left, int right);
        int partition(std::vector<int>& array, int low, int high);
        void quick_helper(std::vector<int>& array, int low, int high);

    public:
        Sorting(std::vector<int> &vec);
        void set_unsorted_array(std::vector<int> vec);
        NumberOfComparisons get_comparisons();
        NumberOfSwaps get_swaps();
        std::vector<int> get_sorted_array();
        bool check_sortedness();
        void print_unsorted();
        void print_sorted();
        void bubble_sort();
        void selection_sort();
        void insertion_sort();
        void merge_sort();
        void quick_sort();
        void reverse_sorted_vector();
};