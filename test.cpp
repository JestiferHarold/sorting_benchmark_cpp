#include <iostream>
#include <random>
#include <vector>
#include "src/sort.cpp"

using namespace std;

int main() {
    int n; 
    cin >> n;

    vector<int> ua;
    random_device rd;

    // mt19937

    for (int i = 0; i < n; i ++) {
        ua[i] = rd();
    }

    Sorting sort(ua);
    sort.bubble_sort();
    sort.check_sorted();
    return 0;
}