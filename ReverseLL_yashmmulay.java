public class ReverseLinkedList {

    // Definition for singly-linked list
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int val) {
            this.val = val;
        }
    }

    public static ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode nextTemp = curr.next; // Store next node
            curr.next = prev;               // Reverse current node's pointer
            prev = curr;                    // Move prev forward
            curr = nextTemp;                // Move curr forward
        }

        return prev; // New head
    }

    // Example usage
    public static void main(String[] args) {
        // Linked List: 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        ListNode reversed = reverseList(head);

        // Print reversed list
        while (reversed != null) {
            System.out.print(reversed.val + " ");
            reversed = reversed.next;
        }
        // Output: 5 4 3 2 1
    }
}
