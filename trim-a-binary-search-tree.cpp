#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while (root && (root->val < low || root->val > high))
            root = (root->val < low) ? root->right : root->left;
        if (!root) return root;

        TreeNode* curr = root;
        while (curr->left) {
            if (curr->left->val < low)
                curr->left = curr->left->right;
            else
                curr = curr->left;
        }

        curr = root;
        while (curr->right) {
            if (curr->right->val > high)
                curr->right = curr->right->left;
            else
                curr = curr->right;
        }

        return root;
    }
};

void inorderPrint(TreeNode* root) {
    if (!root) return;
    inorderPrint(root->left);
    std::cout << root->val << " ";
    inorderPrint(root->right);
}

TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insertBST(root, 3);
    root = insertBST(root, 0);
    root = insertBST(root, 4);
    root = insertBST(root, 2);
    root = insertBST(root, 1);

    int low = 1, high = 3;
    Solution sol;
    TreeNode* trimmed = sol.trimBST(root, low, high);

    std::cout << "Trimmed BST inorder: ";
    inorderPrint(trimmed);
    std::cout << std::endl;

    return 0;
}
