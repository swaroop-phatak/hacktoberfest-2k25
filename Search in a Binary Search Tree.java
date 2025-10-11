// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
    }
}

public class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        // Base case: root is null or value found
        if (root == null || root.val == val)
            return root;

        // If value is smaller, search in the left subtree
        if (val < root.val)
            return searchBST(root.left, val);

        // If value is greater, search in the right subtree
        return searchBST(root.right, val);
    }

    // Example usage
    public static void main(String[] args) {
        // Building a small BST manually
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);

        Solution sol = new Solution();
        TreeNode result = sol.searchBST(root, 2);

        if (result != null)
            System.out.println("Found node with value: " + result.val);
        else
            System.out.println("Value not found in BST");
    }
}
