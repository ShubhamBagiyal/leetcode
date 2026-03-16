// Question 237: Delete Node in a Linked List
// Platform: LeetCode
// Difficulty: Medium
// Link: https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// Helper: build list from array
ListNode* buildList(int arr[], int n) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper: print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 5, 1, 9};
    ListNode* head = buildList(arr, 4);

    // Let's delete node with value 5 (second node)
    ListNode* nodeToDelete = head->next;

    cout << "Before: ";
    printList(head);

    Solution sol;
    sol.deleteNode(nodeToDelete);

    cout << "After:  ";
    printList(head);

    return 0;
}
