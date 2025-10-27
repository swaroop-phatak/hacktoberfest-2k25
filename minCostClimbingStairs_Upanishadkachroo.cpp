/*
 * Description:
 * Given an integer array 'cost' where cost[i] is the cost of step i,
 * find the minimum cost to reach the top of the staircase. You can
 * start at step 0 or step 1, and at each step, you can climb one or
 * two steps.
 *
 * Approach:
 * - Use dynamic programming to compute the minimum cost to reach each step.
 * - Three approaches are possible:
 *   1. Recursive with memoization.
 *   2. Iterative DP using an array.
 *   3. Iterative DP optimized with two variables to store previous results.
 * - For each step i, cost[i] + min(cost to reach i-1, cost to reach i-2)
 *   gives the minimum cost to reach that step.
 * - Finally, return min(cost to reach last step, cost to reach second-last step)
 *   because you can reach the top from either of the last two steps.
 *
 * Time Complexity: O(n)   
 * Space Complexity: O(1)  
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if (n == 1) return cost[0];

        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};

int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost to reach top: " << sol.minCostClimbingStairs(cost) << endl;

    return 0;
}
