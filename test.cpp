#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>
#include <string>
#include <chrono>
#include <fstream>
#include "src/header/sort.hpp"

using namespace std;

typedef string SortingAlgorithm;
typedef int Inputs;
typedef int TimeToSort;
typedef unordered_map<SortingAlgorithm, unordered_map<int, unordered_map<string, long long>>> Record; 

vector<Inputs> number_of_inputs = {
    100,
    500,
    1000,
    5000,
    10000,
    50000,
    100000,
    500000
};

vector<SortingAlgorithm> algos = {
    "BubbleSort",
    "SelectionSort",
    "InsertionSort",
    "MergeSort",
    "Quicksort"
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
        
        record[algos[0]][input]["inputs"] = (SA.check_sortedness() ? time_taken.count() : -999);
        record[algos[0]][input]["swaps"] = SA.get_swaps();
        record[algos[0]][input]["comparisons"] = SA.get_comparisons();

        start = chrono::high_resolution_clock::now();
        SA.selection_sort();
        stop = chrono::high_resolution_clock::now();

        time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << "Time taken to sort an array of size " << input << " using selection sort is " << time_taken.count() << " milliseconds with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";
        
        record[algos[1]][input]["inputs"] = SA.check_sortedness() ? time_taken.count() : -999;
        record[algos[1]][input]["swaps"] = SA.get_swaps();
        record[algos[1]][input]["comparisons"] = SA.get_comparisons();

        start = chrono::high_resolution_clock::now();
        SA.insertion_sort();
        stop = chrono::high_resolution_clock::now();

        time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << "Time taken to sort an array of size " << input << " using insertion sort is " << time_taken.count() << " milliseconds with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";

        record[algos[2]][input]["inputs"] = SA.check_sortedness() ? time_taken.count() : -999;
        record[algos[2]][input]["swaps"] = SA.get_swaps();
        record[algos[2]][input]["comparisons"] = SA.get_comparisons();

        start = chrono::high_resolution_clock::now();
        SA.merge_sort();
        stop = chrono::high_resolution_clock::now();

        time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << "Time taken to sort an array of size " << input << " using merge sort is " << time_taken.count() << " milliseconds with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";

        start = chrono::high_resolution_clock::now();
        SA.quick_sort();
        stop = chrono::high_resolution_clock::now();
        
        time_taken = chrono::duration_cast<chrono::milliseconds>(stop - start);

        cout << "Time taken to sort an array of size " << input << " using quick sort is " << time_taken.count() << " milliseconds with " << SA.get_comparisons() << " Comparisons and " << SA.get_swaps() << " Swaps\n";
        cout << "\n"; 
    }

    fstream fp;
    fp.open("benchmarks.csv", fstream::out);

    fp  << "Sorting algorithm" << ", "
        << "Number of inputs" << ", "
        << "Time Taken to sort Milliseconds" << ", "
        << "Number of Swaps Taken Place" << ", "
        << "Number of Comparisons Taken Place" << "\n";

    for (string algorithm: algos) {
        for (int input: number_of_inputs) {
            fp  << algorithm << ", "
                << input << ", "
                << record[algorithm][input]["inputs"] << ", "
                << record[algorithm][input]["swaps"] << ", "
                << record[algorithm][input]["comparisons"] << "\n";
        }
    }

    fp.close();

    return 0;
}