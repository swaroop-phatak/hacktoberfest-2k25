#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    long long totalCost(std::vector<int>& costs, int k, int candidates) {
        int i = 0;
        int j = costs.size() - 1;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq1;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq2;

        long long ans = 0;
        while (k--) {
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[i++]);
            }
            while (pq2.size() < candidates && i <= j) {
                pq2.push(costs[j--]);
            }

            int t1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int t2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (t1 <= t2) {
                ans += t1;
                pq1.pop();
            } else {
                ans += t2;
                pq2.pop();
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> costs = {10, 20, 15, 30, 5, 40};
    int k = 3;
    int candidates = 2;

    long long result = sol.totalCost(costs, k, candidates);
    std::cout << "Total cost: " << result << std::endl;

    return 0;
}
