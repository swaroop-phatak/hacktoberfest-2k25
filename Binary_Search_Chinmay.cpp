#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // to avoid integer overflow

        if (nums[mid] == target) {
            return mid;  // target found
        } else if (nums[mid] < target) {
            left = mid + 1;  // search in right half
        } else {
            right = mid - 1;  // search in left half
        }
    }

    return -1;  // target not found
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    
    int result = search(nums, target);
    cout << "Output: " << result << endl; // Expected: 4

    return 0;
}
