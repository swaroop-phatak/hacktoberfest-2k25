/*
 * Description:
 * Given a singly linked list, group all the nodes with odd indices together
 * followed by the nodes with even indices. The relative order inside the odd
 * and even groups should remain the same.
 *
 * Example:
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 *
 * Approach:
 * - If the list is empty or has only one node, return it as is.
 * - Use two pointers:
 *   1. `od` pointing to the first node (odd nodes)
 *   2. `evn` pointing to the second node (even nodes)
 * - Keep a pointer `temp` to remember the head of even nodes.
 * - Iterate through the list:
 *   - Link odd nodes together: od->next = evn->next; move od forward.
 *   - Link even nodes together: evn->next = od->next; move evn forward.
 * - After traversal, connect the last odd node to the head of even nodes (`temp`).
 *
 * Time Complexity: O(n)  
 * Space Complexity: O(1)  
 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* od = head;          
        ListNode* evn = head->next;   
        ListNode* temp = evn;          
        while (evn != nullptr && evn->next != nullptr) {
            od->next = evn->next;    
            od = od->next;

            evn->next = od->next;    
            evn = evn->next;
        }

        od->next = temp;               
        return head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, 
                     new ListNode(4, new ListNode(5)))));
    
    Solution sol;
    head = sol.oddEvenList(head);

    cout << "After rearranging odd-even nodes: ";
    printList(head); 
    return 0;
}
