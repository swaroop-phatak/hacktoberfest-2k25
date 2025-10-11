#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;   // Store next
            current->next = prev;   // Reverse current node's pointer
            prev = current;         // Move pointers one position ahead
            current = next;
        }
        head = prev;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.push(5);
    list.push(10);
    list.push(15);
    list.push(20);

    cout << "Original Linked List: ";
    list.printList();

    list.reverse();

    cout << "Reversed Linked List: ";
    list.printList();

    return 0;
}
