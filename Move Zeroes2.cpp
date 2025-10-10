#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int j = 0;  // Pointer to track position of next non-zero element

    // Step 1: Move all non-zero elements to the front
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    cout << "After moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
