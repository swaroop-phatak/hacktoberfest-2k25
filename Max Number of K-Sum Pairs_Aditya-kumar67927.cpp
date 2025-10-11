#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int operations = 0;

    for (int num : nums) {
        int complement = k - num;
        if (freq[complement] > 0) {
            // Found a pair
            operations++;
            freq[complement]--;
        } else {
            freq[num]++;
        }
    }

    return operations;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 3};
    int k = 6;
    cout << "Max number of K-sum pairs: " << maxOperations(nums, k) << endl;
    return 0;
}
