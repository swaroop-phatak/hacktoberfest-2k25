import java.util.*;

public class Maximum_Width_of_Binary_Tree_Shruti03-patil {

    
    static class TreeNode {
        int val;
        TreeNode left, right;
        TreeNode(int x) {
            val = x;
        }
    }

    
    static class NodeIndexPair {
        TreeNode node;
        int index;
        NodeIndexPair(TreeNode node, int index) {
            this.node = node;
            this.index = index;
        }
    }

    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;

        int maxWidth = 0;
        Queue<NodeIndexPair> queue = new LinkedList<>();
        queue.offer(new NodeIndexPair(root, 0));

        while (!queue.isEmpty()) {
            int size = queue.size();
            int minIndex = queue.peek().index; 
            int first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                NodeIndexPair pair = queue.poll();
                int currIndex = pair.index - minIndex; 

                if (i == 0) first = currIndex;
                if (i == size - 1) last = currIndex;

                if (pair.node.left != null)
                    queue.offer(new NodeIndexPair(pair.node.left, 2 * currIndex));
                if (pair.node.right != null)
                    queue.offer(new NodeIndexPair(pair.node.right, 2 * currIndex + 1));
            }

            maxWidth = Math.max(maxWidth, last - first + 1);
        }

        return maxWidth;
    }

   
    public static void main(String[] args) {
        MaxWidthBinaryTree solution = new MaxWidthBinaryTree();

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(3);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(5);
        root.right.right = new TreeNode(9);
        root.left.left.left = new TreeNode(6);
        root.right.right.right = new TreeNode(7);

        int maxWidth = solution.widthOfBinaryTree(root);
        System.out.println("Maximum width: " + maxWidth);  
    }
}
