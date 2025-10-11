#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;

        // Store all values in vector
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        int maxSum = 0;

        // Calculate twin sums
        for (int i = 0; i < n / 2; i++) {
            int twinSum = arr[i] + arr[n - 1 - i];
            maxSum = max(maxSum, twinSum);
        }

        return maxSum;
    }
};


ListNode* createList(vector<int> vals) {
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution obj;
    vector<int> vals = {5, 4, 2, 1};
    ListNode* head = createList(vals);

    cout << obj.pairSum(head);
    return 0;
}
