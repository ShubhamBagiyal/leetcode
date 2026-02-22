// 2095. Delete the Middle Node of a Linked List
// Slow-fast pointer approach with prev tracking

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};

ListNode* deleteMiddle(ListNode* head) {
    if(!head || !head->next) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;

    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}

void display(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // create list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = deleteMiddle(head);

    display(head);
    return 0;
}
