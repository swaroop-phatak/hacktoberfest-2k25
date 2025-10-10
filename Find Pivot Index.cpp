#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) totalSum += num;  // Step 1: Calculate total sum

    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        // Step 2: Check if leftSum == rightSum
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;  // Found pivot index
        }
        leftSum += nums[i];  // Step 3: Update left sum
    }

    return -1;  // No pivot found
}

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    int pivot = pivotIndex(nums);
    cout << "Pivot Index: " << pivot << endl;

    return 0;
}
