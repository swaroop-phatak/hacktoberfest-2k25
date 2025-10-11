#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int left = 0;
    int zeroCount = 0;
    int maxLength = 0;

    for (int right = 0; right < nums.size(); ++right) {
        if (nums[right] == 0)
            zeroCount++;

        while (zeroCount > 1) {
            if (nums[left] == 0)
                zeroCount--;
            left++;
        }

        maxLength = max(maxLength, right - left);
    }

    return maxLength;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1};
    cout << "Longest subarray of 1s after deleting one element: " << longestSubarray(nums) << endl;
    return 0;
}
