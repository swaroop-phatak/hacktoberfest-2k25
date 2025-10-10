#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int n : nums) {
            result ^= n;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 2, 1};
    cout << "Input: [2, 2, 1]\nOutput: " << sol.singleNumber(nums1) << endl;

    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "\nInput: [4, 1, 2, 1, 2]\nOutput: " << sol.singleNumber(nums2) << endl;

    vector<int> nums3 = {1};
    cout << "\nInput: [1]\nOutput: " << sol.singleNumber(nums3) << endl;

    return 0;
}
