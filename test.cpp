#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>
#include <string>
#include <chrono>
#include "src/header/sort.hpp"

using namespace std;

typedef string SortingAlgorithm;
typedef int Inputs;
typedef int TimeToSort;
typedef unordered_map<SortingAlgorithm, unordered_map<int, unordered_map<string, int>>> Record; /* vector<TimeToSort, swaps, comparisons> */

vector<Inputs> number_of_inputs = {
    1000,
    10000,
    50000,
    100000,
    500000
};

vector<SortingAlgorithm> algos = {
    "Bubble sort",
    "Selection sort",
    "Insertion sort",
    "Merge sort",
    "Quick sort"
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
    Record record;
    chrono::steady_clock::time_point start, stop;
    vector<int> storage;
    Sorting SA(storage);

    for (int input: number_of_inputs) {
        storage = get_random_inputs(input);
        SA.set_unsorted_array(storage);

        start = chrono::high_resolution_clock::now();
        SA.bubble_sort();
        stop = chrono::high_resolution_clock::now();

        chrono::duration time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << "Time Taken to sort an array of size " << input << " using bubble sort is " << time_taken.count() << " milliseconds"  << " with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";
        
        record["BubbleSort"][input]["inputs"] = (SA.check_sortedness() ? time_taken.count() : -999);
        record["BubbleSort"][input]["swaps"] = SA.get_swaps();
        record["BubbleSort"][input]["comparisons"] = SA.get_comparisons();

        start = chrono::high_resolution_clock::now();
        SA.selection_sort();
        stop = chrono::high_resolution_clock::now();

        time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << "Time taken to sort an array of size " << input << " using selection sort is " << time_taken.count() << " milliseconds with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";
        
        record["SelectionSort"][input]["inputs"] = SA.check_sortedness() ? time_taken.count() : -999;
        record["SelectionSort"][input]["swaps"] = SA.get_swaps();
        record["SelectionSort"][input]["comparisons"] = SA.get_comparisons();

        start = chrono::high_resolution_clock::now();
        SA.insertion_sort();
        stop = chrono::high_resolution_clock::now();

        time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << "Time taken to sort an array of size " << input << " using insertion sort is " << time_taken.count() << " milliseconds with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";

        record["InsertionSort"][input]["inputs"] = SA.check_sortedness() ? time_taken.count() : -999;
        record["InsertionSort"][input]["swaps"] = SA.get_swaps();
        record["InsertionSort"][input]["comparisons"] = SA.get_comparisons();
        cout << "\n";
    }

    return 0;
}