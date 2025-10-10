#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int zeroCount = 0;

    while (right < nums.size()) {
        // If we encounter a zero, increment zeroCount
        if (nums[right] == 0)
            zeroCount++;

        // If zeroCount exceeds k, shrink the window from left
        while (zeroCount > k) {
            if (nums[left] == 0)
                zeroCount--;
            left++;
        }

        // Calculate max window size
        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << "Maximum Consecutive 1s (after flipping at most " << k << " zeros): "
         << longestOnes(nums, k) << endl;
    return 0;
}
