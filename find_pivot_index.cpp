/*
Problem Statement:
-->Given an array of integers nums, find the pivot index.
The pivot index is the index where the sum of all numbers to the left
of the index is equal to the sum of all numbers to the right.
-->If no such index exists, return -1.
-->If there are multiple pivot indexes, return the left-most pivot index. 
*/


#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    Solution sol;
    cout << "Pivot index: " << sol.pivotIndex(nums) << endl; // Output: 3
    return 0;
}


// Time Complexity: O(n)
// Space Complexity: O(1)