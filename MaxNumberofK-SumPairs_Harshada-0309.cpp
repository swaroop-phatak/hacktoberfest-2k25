#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;

        for (int num : nums) {
            int target = k - num;
            if (mp[target] > 0) {
                count++;
                mp[target]--;
            } else {
                mp[num]++;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    int k = 5;

    cout << "Maximum number of k-sum pairs: " << s.maxOperations(nums, k);
    return 0;
}
