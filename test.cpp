#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>
#include <string>
#include <chrono>
#include "src/header/sort.hpp"

using namespace std;

typedef unordered_map<string, unordered_map<int, int>> unnamed;

int main() {

    int n;
    cin >> n;

    vector<int> ua;
    random_device rd;

    for (int i = 0; i < n; i ++) {
        ua.push_back(rd());
    }

    Sorting sd = Sorting(ua);
    cout << "Unsorted array\n";
    // sd.print_unsorted();
    auto start = chrono::high_resolution_clock::now();  
    sd.bubble_sort();
    auto stop = chrono::high_resolution_clock::now();
    cout << "Sorted array\n";
    // sd.print_sorted();
    // sd.check_sortedness();

    auto duration = chrono::duration_cast<chrono::minutes>(stop - start);

    cout << "\nTime taken to do bubble sort for " << n << " elements is " << duration.count();

    return 0;
}