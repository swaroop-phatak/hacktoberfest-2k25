#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> aboveRow(n, 1);

        for (int row = 1; row < m; row++) {
            std::vector<int> currentRow(n, 1);
            for (int col = 1; col < n; col++) {
                currentRow[col] = currentRow[col - 1] + aboveRow[col];
            }
            aboveRow = currentRow;
        }

        return aboveRow[n - 1];        
    }
};

int main() {
    Solution solution;
    int m = 3, n = 7;

    int result = solution.uniquePaths(m, n);
    std::cout << "Number of unique paths from top-left to bottom-right in a " 
              << m << "x" << n << " grid is: " << result << std::endl;

    return 0;
}
