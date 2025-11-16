#pragma once

#include <vector>

class Sorting {
    private:
        std::vector<int> unsorted_array;
        std::vector<int> sorted_array;

    public:
        Sorting(std::vector<int> &vec);
        void set_unsorted_array(std::vector<int> vec);
        void check_sortedness();
        void print_unsorted();
        void print_sorted();
        void bubble_sort();
        void selection_sort();
        void insertion_sort();
        void merge_sort();
        void quick_sort();
};