#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to get right side view
vector<int> rightSideView(Node* root) {
    vector<int> view;
    if (!root) return view;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            // last node at each level
            if (i == size - 1)
                view.push_back(node->data);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }

    return view;
}

// Helper: print the view
void printVector(const vector<int>& v) {
    for (int val : v)
        cout << val << " ";
    cout << endl;
}

int main() {
    /*
        Constructed binary tree:
                1
               / \
              2   3
               \   \
                5   4
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);

    cout << "Right Side View: ";
    vector<int> result = rightSideView(root);
    printVector(result);

    return 0;
}
