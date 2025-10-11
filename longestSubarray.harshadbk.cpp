#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int left = 0, right = 0;
    int zeroCount = 0;
    int maxLen = 0;

    while (right < nums.size()) {
        if (nums[right] == 0)
            zeroCount++;

        while (zeroCount > 1) {
            if (nums[left] == 0)
                zeroCount--;
            left++;
        }

        maxLen = max(maxLen, right - left);
        right++;
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1, 1, 0, 1};
    cout << "Longest subarray of 1's after deleting one element: " 
         << longestSubarray(nums) << endl;

    return 0;
}
