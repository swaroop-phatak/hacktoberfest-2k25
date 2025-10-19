class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1, n2 = len(word1), len(word2)
        
        # dp[i][j] is the minimum number of operations to convert word1[:i] to word2[:j]
        dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]

        # Base case 1: Converting word1[:i] to an empty string (word2[:0]) requires i deletions
        for i in range(n1 + 1):
            dp[i][0] = i
        
        # Base case 2: Converting an empty string (word1[:0]) to word2[:j] requires j insertions
        for j in range(n2 + 1):
            dp[0][j] = j
            
        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                if word1[i-1] == word2[j-1]:
                    # Characters match: No operation needed (same as previous subproblem)
                    dp[i][j] = dp[i-1][j-1]
                else:
                    # Characters don't match: take min of 3 operations + 1
                    dp[i][j] = 1 + min(
                        dp[i-1][j],   # Deletion (of word1[i-1])
                        dp[i][j-1],   # Insertion (of word2[j-1])
                        dp[i-1][j-1]  # Replacement (of word1[i-1] with word2[j-1])
                    )
                    
        return dp[n1][n2]
