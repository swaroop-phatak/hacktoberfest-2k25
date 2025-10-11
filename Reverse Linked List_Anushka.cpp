#include <bits/stdc++.h>
using namespace std;

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* nextNode = curr->next; // store next node
        curr->next = prev;               // reverse the pointer
        prev = curr;                     // move prev forward
        curr = nextNode;                 // move curr forward
    }

    return prev; // new head
}

// -- Example Usage
int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = reverseList(head);

    // Print reversed list: 5 -> 4 -> 3 -> 2 -> 1
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
