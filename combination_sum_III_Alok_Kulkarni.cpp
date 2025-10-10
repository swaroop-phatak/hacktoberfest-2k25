#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ansArr;

public:
    int sum(vector<int>& combination) {
        int ans = 0;
        for (auto x : combination) {
            ans += x;
        }
        return ans;
    }

    void combinationSumHelper(int k, int n, vector<int>& combination, int num) {
        if (k == 0) {
            if (sum(combination) == n) {
                ansArr.push_back(combination);
            }
            return;
        }

        if (num > 9) return;


        combination.push_back(num);
        combinationSumHelper(k - 1, n, combination, num + 1);
        combination.pop_back();
        combinationSumHelper(k, n, combination, num + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        ansArr.clear(); 
        vector<int> combination;
        combinationSumHelper(k, n, combination, 1);
        return ansArr;
    }
};

int main() {
    Solution sol;

    int k = 3;
    int n = 7;

    vector<vector<int>> result = sol.combinationSum3(k, n);

    cout << "Combinations of " << k << " numbers that sum to " << n << ":\n";
    for (const auto& combo : result) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
