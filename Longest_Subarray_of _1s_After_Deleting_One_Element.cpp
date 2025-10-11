#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeroCount = 0, maxLen = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeroCount++;
            while (zeroCount > 1) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }
            maxLen = max(maxLen, right - left);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 1, 0, 1};
    cout << "Input: [1, 1, 0, 1]\nOutput: " << sol.longestSubarray(nums1) << endl;

    vector<int> nums2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << "\nInput: [0, 1, 1, 1, 0, 1, 1, 0, 1]\nOutput: " << sol.longestSubarray(nums2) << endl;

    vector<int> nums3 = {1, 1, 1};
    cout << "\nInput: [1, 1, 1]\nOutput: " << sol.longestSubarray(nums3) << endl;

    return 0;
}
