#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int zeros = 0, maxLen = 0;

        while (right < nums.size()) {
            if (nums[right] == 0)
                zeros++;

            // If more than k zeros, shrink the window
            while (zeros > k) {
                if (nums[left] == 0)
                    zeros--;
                left++;
            }

            // Update max length
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << sol.longestOnes(nums, k) << endl; // Expected output: 6
    return 0;
}
