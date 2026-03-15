//leetcode 19 DeleteNthNodeFromEnd.cpp
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        for(int i = 0; i < n + 1; i++){
            fast = fast->next;
        }

        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy.next;
    }
};

// Helper: build linked list from array
ListNode* buildList(int arr[], int size){
    if(size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for(int i = 1; i < size; i++){
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper: print linked list
void printList(ListNode* head){
    while(head != nullptr){
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL" << endl;
}

// Helper: free memory
void freeList(ListNode* head){
    while(head){
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    Solution sol;

    // Test 1: 1->2->3->4->5, n=2  =>  1->2->3->5
    int arr1[] = {1, 2, 3, 4, 5};
    ListNode* head1 = buildList(arr1, 5);
    cout << "Input:  "; printList(head1);
    head1 = sol.removeNthFromEnd(head1, 2);
    cout << "Output: "; printList(head1);
    freeList(head1);

    cout << endl;

    // Test 2: single node [1], n=1  =>  NULL
    int arr2[] = {1};
    ListNode* head2 = buildList(arr2, 1);
    cout << "Input:  "; printList(head2);
    head2 = sol.removeNthFromEnd(head2, 1);
    cout << "Output: "; printList(head2);
    freeList(head2);

    cout << endl;

    // Test 3: 1->2, n=1  =>  1
    int arr3[] = {1, 2};
    ListNode* head3 = buildList(arr3, 2);
    cout << "Input:  "; printList(head3);
    head3 = sol.removeNthFromEnd(head3, 1);
    cout << "Output: "; printList(head3);
    freeList(head3);

    cout << endl;

    // Test 4: 1->2, n=2  =>  2 (remove head)
    int arr4[] = {1, 2};
    ListNode* head4 = buildList(arr4, 2);
    cout << "Input:  "; printList(head4);
    head4 = sol.removeNthFromEnd(head4, 2);
    cout << "Output: "; printList(head4);
    freeList(head4);

    return 0;
}
