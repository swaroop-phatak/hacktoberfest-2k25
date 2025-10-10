class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val=val;
    }
}

public class RootEqualsSum{
    public static boolean checkTree(TreeNode root) {
        return root.val==root.left.val+root.right.val;
    }

    public static void main(String[] args) {
        TreeNode root=new TreeNode(10);
        root.left=new TreeNode(4);
        root.right=new TreeNode(6);

        System.out.println(checkTree(root));
    }
}
