class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # Initialize DP array for the first row (or use O(n) space)
        row = [1] * n # Represents the DP row for m=1

        for i in range(1, m):
            new_row = [1] * n
            for j in range(1, n):
                # uniquePaths(i, j) = uniquePaths(i-1, j) + uniquePaths(i, j-1)
                new_row[j] = new_row[j-1] + row[j]
            row = new_row
            
        return row[-1]
