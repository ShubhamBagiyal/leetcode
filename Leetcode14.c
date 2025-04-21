//LINKED LIST REVERSE BETWEEN LEFT AND RIGHT

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to reverse a portion of the list between positions left and right
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || left == right) return head;

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;

    // Move prev to the node before `left`
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // Reverse the sublist
    struct ListNode* curr = prev->next;
    struct ListNode* nextnode = NULL;
    for (int i = 0; i < right - left; i++) {
        nextnode = curr->next;
        curr->next = nextnode->next;
        nextnode->next = prev->next;
        prev->next = nextnode;
    }

    head = dummy->next;
    return head;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Creating a sample list: 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int left = 2, right = 4;

    printf("Original list:\n");
    printList(head);

    head = reverseBetween(head, left, right);

    printf("List after reversing between %d and %d:\n", left, right);
    printList(head);

    return 0;
}