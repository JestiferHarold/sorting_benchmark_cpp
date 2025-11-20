#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <algorithm>
#include "src/header/sort.hpp"

using namespace std;

typedef string SortingAlgorithm;
typedef long long Inputs;
typedef int TimeToSort;

vector<Inputs> number_of_inputs = {
    100,
    500,
    1000,
    5000,
    10000,
    // 50000,
    // 100000, 
    // 500000
};

random_device rd;

vector<int> get_random_inputs(Inputs n) {
    vector<int> v;
    
    for (int i = 0; i < n; i ++) {
        v.push_back(rd());
    }

    return v;
}

int main() {
    vector<int> storage;
    Sorting SA(storage);

    ofstream fp("benchmarks.csv");
    
    fp  << "Sorting algorithm,"
        << "Case,"
        << "Number of inputs,"
        << "Time Taken to sort Milliseconds,"
        << "Number of Swaps Taken Place,"
        << "Number of Comparisons Taken Place\n";

    for (auto input: number_of_inputs) {
        storage = get_random_inputs(input);
        SA.set_unsorted_array(storage);
        for (const string s: {"average", "worst", "best"}) {

            if (s == "best") {
                sort(storage.begin(), storage.end());
                SA.set_unsorted_array(storage);
            } else if (s == "worst") {
                reverse(storage.begin(), storage.end());
                SA.set_unsorted_array(storage);
            }

            cout << s << " case, input size: " << input << "\n\n";

            auto start = chrono::high_resolution_clock::now();
            SA.bubble_sort();
            auto stop = chrono::high_resolution_clock::now();

            chrono::milliseconds time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

            cout << "Time Taken to sort an array of size " << input << " using bubble sort is " << time_taken.count() << " milliseconds"  << " with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";
            
            fp  << "Bubble Sort,"
                << s << ","
                << input << ","
                << (SA.check_sortedness() ? time_taken.count() : -999) << ","
                << SA.get_swaps() << ","
                << SA.get_comparisons() << "\n";

            start = chrono::high_resolution_clock::now();
            SA.selection_sort();
            stop = chrono::high_resolution_clock::now();

            time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

            cout << "Time taken to sort an array of size " << input << " using selection sort is " << time_taken.count() << " milliseconds with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";
            
            fp  << "Selection Sort,"
                << s << ","
                << input << ","
                << (SA.check_sortedness() ? time_taken.count() : -999) << ","
                << SA.get_swaps() << ","
                << SA.get_comparisons() << "\n";

            start = chrono::high_resolution_clock::now();
            SA.insertion_sort();
            stop = chrono::high_resolution_clock::now();

            time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

            cout << "Time taken to sort an array of size " << input << " using insertion sort is " << time_taken.count() << " milliseconds with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";

            fp  << "Insertion Sort,"
                << s << ","
                << input << ","
                << (SA.check_sortedness() ? time_taken.count() : -999) << ","
                << SA.get_swaps() << ","
                << SA.get_comparisons() << "\n";

            start = chrono::high_resolution_clock::now();
            SA.merge_sort();
            stop = chrono::high_resolution_clock::now();

            time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

            cout << "Time taken to sort an array of size " << input << " using merge sort is " << time_taken.count() << " milliseconds with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";

            fp  << "Merge Sort,"
                << s << ","
                << input << ","
                << (SA.check_sortedness() ? time_taken.count() : -999) << ","
                << SA.get_swaps() << ","
                << SA.get_comparisons() << "\n";

            start = chrono::high_resolution_clock::now();
            SA.quick_sort();
            stop = chrono::high_resolution_clock::now();
            
            time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

            cout << "Time taken to sort an array of size " << input << " using quick sort is " << time_taken.count() << " milliseconds with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";
            cout << "\n"; 

            fp  << "Quick Sort,"
                << s << ","
                << input << ","
                << (SA.check_sortedness() ? time_taken.count() : -999) << ","
                << SA.get_swaps() << ","
                << SA.get_comparisons() << "\n";
        }
    }

    fp.close();
    return 0;
}