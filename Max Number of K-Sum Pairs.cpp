#include <bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int num : nums) {
        int complement = k - num;
        if (freq[complement] > 0) {
            count++;
            freq[complement]--;  // Use the complement
        } else {
            freq[num]++;  // Store this number for future pairs
        }
    }

    return count;
}

int main() {
    vector<int> nums;
    int n, k, temp;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    cout << "Enter k: ";
    cin >> k;

    int result = maxOperations(nums, k);
    cout << "Maximum number of K-sum pairs: " << result << endl;

    return 0;
}
