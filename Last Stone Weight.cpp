// Last Stone Weight - C++ (uses max-heap)
// Given an array stones, repeatedly smash the two heaviest stones:
// if equal -> both destroyed; if different -> push back the difference.
// Return the weight of the last stone or 0 if none remain.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int w : stones) pq.push(w);

        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if (a != b) pq.push(a - b);
        }

        return pq.empty() ? 0 : pq.top();
    }
};

// Example usage (not needed on LeetCode, but useful for local testing):
int main() {
    Solution sol;
    vector<int> stones = {2,7,4,1,8,1};
    cout << sol.lastStoneWeight(stones) << "\n"; // expected output: 1
    return 0;
}
