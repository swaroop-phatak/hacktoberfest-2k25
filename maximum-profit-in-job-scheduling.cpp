#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        int n = startTime.size();
        std::vector<std::vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        std::sort(jobs.begin(), jobs.end());
        std::map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int cur = std::prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
};

int main() {
    Solution solution;
    std::vector<int> startTime = {1, 2, 3, 3};
    std::vector<int> endTime = {3, 4, 5, 6};
    std::vector<int> profit = {50, 10, 40, 70};

    int result = solution.jobScheduling(startTime, endTime, profit);
    std::cout << "Maximum profit: " << result << std::endl;

    return 0;
}
