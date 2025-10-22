#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Compare mid and mid + 1 to decide which side has a peak
        if (nums[mid] > nums[mid + 1]) {
            // Peak is on the left (including mid)
            right = mid;
        } else {
            // Peak is on the right
            left = mid + 1;
        }
    }

    // left == right → peak index
    return left;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << findPeakElement(nums) << endl;  // Output: 2
    return 0;
}
