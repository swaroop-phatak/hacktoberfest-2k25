#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class LinkedList {
public:
    ListNode* head;

    LinkedList() {
        head = NULL;
    }

    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void oddEvenList() {
        if (head == NULL || head->next == NULL) {
            return;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != NULL && even->next != NULL) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
    }

    void print() {
        ListNode* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "Original Linked List: ";
    list.print();

    list.oddEvenList();

    cout << "Odd-Even Reordered Linked List: ";
    list.print();

    return 0;
}
