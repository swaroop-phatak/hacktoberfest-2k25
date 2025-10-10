#include <iostream>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            root = (val < root->val) ? root->left : root->right;
        }
        return root;
    }
};

int main() {
  
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int target = 2;
    TreeNode* res = sol.searchBST(root, target);

    if (res) cout << "Found subtree with root value: " << res->val << endl;
    else cout << "Value not found" << endl;

    return 0;
}
