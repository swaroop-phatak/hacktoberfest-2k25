#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int x : arr) freq[x]++;

        unordered_set<int> seen;
        for (auto &p : freq) {
            if (!seen.insert(p.second).second) {
                // insertion failed => this frequency already exists
                return false;
            }
        }
        return true;
    }
};

// -- Example usage (simple test)
int main() {
    Solution sol;
    vector<int> a1 = {1,2,2,1,1,3};   // frequencies: 1->3, 2->2, 3->1 -> all unique -> true
    vector<int> a2 = {1,2,2,3,3};     // frequencies: 1->1, 2->2, 3->2 -> 2 repeats -> false

    cout << boolalpha;
    cout << "a1: " << sol.uniqueOccurrences(a1) << "\n"; // prints: a1: true
    cout << "a2: " << sol.uniqueOccurrences(a2) << "\n"; // prints: a2: false
    return 0;
}
