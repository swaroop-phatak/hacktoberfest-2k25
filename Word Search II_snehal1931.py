from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        # 1. Build the Trie
        root = TrieNode()
        for word in words:
            node = root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.word = word
        
        ROWS, COLS = len(board), len(board[0])
        res = set() # Use a set to avoid duplicate words
        
        def dfs(r, c, node):
            char = board[r][c]
            
            # Check if current cell is visited or not in trie
            if char == '#': 
                return
            if char not in node.children:
                return
            
            # Move to the next node
            node = node.children[char]

            # Check for word
            if node.word:
                res.add(node.word)
                # Optimization: Don't return here, a longer word might exist.
                # However, for LeetCode constraints, marking it found/deleted is faster.
                # node.word = None # Optional: Mark as found to avoid re-adding

            # Mark current cell as visited
            board[r][c] = '#'

            # Explore neighbors (Up, Down, Left, Right)
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < ROWS and 0 <= nc < COLS:
                    dfs(nr, nc, node)
            
            # Unmark current cell (Backtrack)
            board[r][c] = char

        # Start DFS from every cell
        for r in range(ROWS):
            for c in range(COLS):
                dfs(r, c, root)

        return list(res)
