#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> diff1, diff2;
        
        for (int num : set1)
            if (set2.find(num) == set2.end())
                diff1.push_back(num);
        
        for (int num : set2)
            if (set1.find(num) == set1.end())
                diff2.push_back(num);
        
        return {diff1, diff2};
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    
    vector<vector<int>> ans = sol.findDifference(nums1, nums2);
    
    cout << "Unique in nums1: ";
    for (int x : ans[0]) cout << x << " ";
    cout << "\nUnique in nums2: ";
    for (int x : ans[1]) cout << x << " ";
    cout << endl;
    
    return 0;
}
