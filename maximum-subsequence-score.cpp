#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        int n = nums1.size();
        std::vector<std::pair<int,int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {nums2[i], nums1[i]};
        }
        std::sort(pairs.rbegin(), pairs.rend());  // sort by nums2 descending
        
        long long sum1 = 0;
        long long result = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;  // min‐heap of selected nums1 values
        
        for (auto &p : pairs) {
            int e = p.first;   // value from nums2
            int s = p.second;  // corresponding value from nums1
            minheap.push(s);
            sum1 += s;
            if ((int)minheap.size() > k) {
                sum1 -= minheap.top();
                minheap.pop();
            }
            if ((int)minheap.size() == k) {
                long long score = sum1 * (long long)e;
                if (score > result) result = score;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1,3,3,2};
    std::vector<int> nums2 = {2,1,3,4};
    int k = 3;
    long long ans = sol.maxScore(nums1, nums2, k);
    std::cout << "Maximum subsequence score: " << ans << std::endl;
    return 0;
}
