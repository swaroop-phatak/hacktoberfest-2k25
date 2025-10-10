#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int ans = 0;
    int pathSum(TreeNode* root, int sum) {
        if (root) {
            dfs(root, sum);
            pathSum(root->left, sum);
            pathSum(root->right, sum);
        }
        return ans;
    }
    void dfs(TreeNode* root, int sum) {
        if (!root) return;
        if (root->val == sum) ans++;
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution sol;
    int sum = 8;
    cout << sol.pathSum(root, sum) << endl;

    return 0;
}
