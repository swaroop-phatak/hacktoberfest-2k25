#include <bits/stdc++.h>
using namespace std;

int equalPairs(vector<vector<int>>& grid) {
    int n = grid.size();
    map<vector<int>, int> rows;
    for (auto& r : grid) rows[r]++;
    int ans = 0;
    for (int c = 0; c < n; c++) {
        vector<int> col;
        for (int r = 0; r < n; r++) col.push_back(grid[r][c]);
        ans += rows[col];
    }
    return ans;
}

int main() {
    vector<vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
    cout << equalPairs(grid);
}
