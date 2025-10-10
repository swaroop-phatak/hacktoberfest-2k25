#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums) {
    int left = 0,zeros = 0,maxLen = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) {
            zeros++;
        }
        while (zeros > 1) {
            if (nums[left] == 0) {
                zeros--;
            }
            left++;
        }
        maxLen = max(maxLen, right - left);
    }
    return maxLen;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1};
    cout << "Longest subarray of 1's after deleting one element: ";
    int result = longestSubarray(nums);
    cout << result << endl;
    return 0;
}
