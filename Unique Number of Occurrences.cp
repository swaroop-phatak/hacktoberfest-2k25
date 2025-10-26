#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    // Step 1: Count frequencies
    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }

    // Step 2: Get all occurrence counts
    unordered_set<int> counts;
    for (auto& p : freq) {
        // If count already exists → not unique
        if (counts.count(p.second))
            return false;
        counts.insert(p.second);
    }

    // Step 3: All counts are unique
    return true;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    vector<int> arr2 = {1, 2};
    vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    cout << boolalpha; // print true/false instead of 1/0
    cout << uniqueOccurrences(arr1) << endl; // true
    cout << uniqueOccurrences(arr2) << endl; // false
    cout << uniqueOccurrences(arr3) << endl; // true

    return 0;
}
