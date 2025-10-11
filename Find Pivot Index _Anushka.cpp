#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }

        return -1; // no pivot found
    }
};

// -- Example Usage
int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    int pivot = sol.pivotIndex(nums);
    cout << "Pivot Index: " << pivot << "\n"; // Output: 3

    return 0;
}
