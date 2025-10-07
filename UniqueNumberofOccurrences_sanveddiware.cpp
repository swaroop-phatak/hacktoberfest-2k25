#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr)
            freq[num]++;

        unordered_set<int> seen;
        for (auto& [key, val] : freq) {
            if (seen.count(val)) return false;
            seen.insert(val);
        }

        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << (sol.uniqueOccurrences(arr) ? "true" : "false");  // Output: true
    return 0;
}
