#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());

    vector<int> diff1, diff2;

    // Elements in nums1 not in nums2
    for (int num : set1) {
        if (set2.find(num) == set2.end())
            diff1.push_back(num);
    }

    // Elements in nums2 not in nums1
    for (int num : set2) {
        if (set1.find(num) == set1.end())
            diff2.push_back(num);
    }

    return {diff1, diff2};
}

// -- Example Usage
int main() {
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4,6};

    vector<vector<int>> res = findDifference(nums1, nums2);

    for (auto &v : res) {
        cout << "[ ";
        for (int x : v) cout << x << " ";
        cout << "] ";
    }
    cout << endl; // Output: [ 1 3 ] [ 4 6 ]

    return 0;
}
