#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-heap to store {distance, point}
        priority_queue<pair<int, pair<int, int>>> pq;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            int dist = x * x + y * y;  // No need to take sqrt, just compare squares
            pq.push({dist, {x, y}});

            if (pq.size() > k)
                pq.pop(); // remove farthest point
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int k = 2;

    vector<vector<int>> ans = sol.kClosest(points, k);

    for (auto& p : ans)
        cout << "[" << p[0] << ", " << p[1] << "] ";
    cout << endl;

    // Expected output: [-2,4] [3,3]  (order may vary)
    return 0;
}
