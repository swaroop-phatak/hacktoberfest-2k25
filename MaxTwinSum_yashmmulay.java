public class MaximumTwinSumLinkedList {

    // Definition for singly-linked list
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) {
            this.val = val;
        }
    }

    public static int pairSum(ListNode head) {
        if (head == null) return 0;

        // 1️⃣ Find the middle using slow & fast pointers
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // 2️⃣ Reverse the second half of the list
        ListNode secondHalf = reverseList(slow);

        // 3️⃣ Compare first half and reversed second half to find max twin sum
        ListNode firstHalf = head;
        int maxSum = 0;
        while (secondHalf != null) {
            int twinSum = firstHalf.val + secondHalf.val;
            maxSum = Math.max(maxSum, twinSum);
            firstHalf = firstHalf.next;
            secondHalf = secondHalf.next;
        }

        return maxSum;
    }

    // Helper: reverse a linked list
    private static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    // Example usage
    public static void main(String[] args) {
        // Linked List: 1 -> 2 -> 3 -> 4
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);

        System.out.println(pairSum(head)); // Output: 5
    }
}
