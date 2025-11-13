#include <vector>
#include <iostream>

using namespace std;

class Sorting {
    private: 
        vector<int> unsorted_array;
        vector<int> sorted_array;

    public:
        Sorting(vector<int> &vec) {
            this->unsorted_array = vec;
            cout << "Working";
        }

        void check_sorted() {

            if (sorted_array.size() == 0) {
                cout << "0 Elements" << "\n";
            }

            if (sorted_array.size() != unsorted_array.size()) {
                cout << "Elements missing from the sorted array" << "\n";
            }

            int min = this->sorted_array[0];

            for (int a: this->sorted_array) {
                if (min > a) {
                    cout << "Vector is still unsorted" << "\n";
                    return;
                }
            }

            cout << "Vector is sorted" << "\n";
        }

        void print_sorted() {
            for (auto a: this->sorted_array) {
                
            }
        }

        void bubble_sort();
        void selection_sort();
        void insertion_sort();
        void merge_sort();
        void quick_sort();
};