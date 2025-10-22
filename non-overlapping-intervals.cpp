#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static bool cmp(std::vector<int>& a, std::vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        std::sort(intervals.begin(), intervals.end(), cmp);

        int prev = 0;
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= intervals[prev][1]) {
                prev = i;
                count++;
            }
        }
        return n - count;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> intervals = {
        {1, 2}, {2, 3}, {3, 4}, {1, 3}
    };

    int result = solution.eraseOverlapIntervals(intervals);
    std::cout << "Minimum number of intervals to remove: " << result << std::endl;

    return 0;
}
