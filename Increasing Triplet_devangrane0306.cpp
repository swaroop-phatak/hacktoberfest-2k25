#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int smallest = INT_MAX;  // smallest value so far
        int middle = INT_MAX;    // second smallest value so far

        for (int num : nums) {
            if (num <= smallest) {
                smallest = num;  // update smallest if num is smaller
            } else if (num <= middle) {
                middle = num;    // update middle if num is between smallest and middle
            } else {
                // If we find a num greater than both smallest and middle, triplet exists
                return true;
            }
        }
        return false;  // no increasing triplet subsequence found
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    if (solution.increasingTriplet(nums)) {
        cout << "Increasing triplet subsequence exists." << endl;
    } else {
        cout << "No increasing triplet subsequence." << endl;
    }
    return 0;
}
