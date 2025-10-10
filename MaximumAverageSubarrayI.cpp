#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) return 0;

    double sum = 0;
    // Sum of first k elements
    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    double maxSum = sum;

    // Sliding window
    for (int i = k; i < n; i++) {
        sum += nums[i] - nums[i - k]; // Add new element, remove oldest
        if (sum > maxSum) maxSum = sum;
    }

    return maxSum / k;
}

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    
    cout << "Maximum average subarray: " << findMaxAverage(nums, k) << endl;
    
    return 0;
}
