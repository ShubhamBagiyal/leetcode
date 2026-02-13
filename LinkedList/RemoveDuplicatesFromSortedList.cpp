
//83. Remove Duplicates from Sorted List


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* p = head;

        while(p && p->next) {

            if(p->val == p->next->val) {

                ListNode* temp = p->next;
                p->next = p->next->next;
                delete temp;
            }
            else {
                p = p->next;
            }
        }

        return head;
    }
};

void printList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Create sample list: 1->1->2->3->3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution obj;
    head = obj.deleteDuplicates(head);

    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}

