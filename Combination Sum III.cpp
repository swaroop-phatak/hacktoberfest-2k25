#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int k, int n, int start, vector<int>& path) {
        if (k == 0 && n == 0) {
            result.push_back(path);
            return;
        }
        if (k == 0 || n < 0) return;

        for (int i = start; i <= 9; i++) {
            path.push_back(i);
            backtrack(k - 1, n - i, i + 1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        backtrack(k, n, 1, path);
        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    int k = 3, n = 7;
    vector<vector<int>> ans = sol.combinationSum3(k, n);

    for (auto &vec : ans) {
        for (int x : vec) cout << x << " ";
        cout << endl;
    }
    // Expected output:
    // 1 2 4
    return 0;
}
