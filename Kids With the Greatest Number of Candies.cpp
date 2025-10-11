#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> result;

        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= maxCandies) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    vector<bool> ans = obj.kidsWithCandies(candies, extraCandies);
    for (bool val : ans) {
        cout << (val ? "true " : "false ");
    }
    return 0;
}
