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
typedef unordered_map<SortingAlgorithm, unordered_map<Inputs, TimeToSort>> Record;

vector<Inputs> number_of_inputs = {
    1000,
    10000,
    100000,
    500000
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
        cout << "Time Taken to sort an array of size " << input << " using bubble sort is " << time_taken.count() << " milliseconds\n";
    }

    return 0;
}