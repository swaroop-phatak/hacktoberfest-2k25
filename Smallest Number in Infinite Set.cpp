#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxLen = 0;

    void dfs(TreeNode* node, bool isLeft, int length) {
        if (!node) return;
        maxLen = max(maxLen, length);

        if (isLeft) {
            dfs(node->left, false, 1);         // move left → reset count
            dfs(node->right, true, length + 1); // move right → continue zigzag
        } else {
            dfs(node->right, true, 1);          // move right → reset count
            dfs(node->left, false, length + 1); // move left → continue zigzag
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return maxLen;
    }
};

// Example usage
int main() {
    /*
        Example Tree:
              1
             / \
            2   3
             \
              4
               \
                5
                 \
                  6
        Expected output: 4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    Solution sol;
    cout << sol.longestZigZag(root) << endl;
    return 0;
}
