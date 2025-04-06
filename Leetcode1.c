//REVERSE LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void traverselinkedlist(struct node *ptr) {
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node* reverselinkedlist(struct node *head) {
    struct node *prevnode = NULL, *currentnode = head, *nextnode = NULL;
    while(currentnode!=NULL){
        nextnode=currentnode->next;      //set nextnode
        currentnode->next=prevnode;      //link prevnode<-currentnode
        prevnode=currentnode;            //set prev to current
        currentnode=nextnode;            //set current to next
    }
    return prevnode;                     //return prevnode as head to call
}

int main() {
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS: ");
    scanf("%d", &n);
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* p = head;

    printf("ENTER THE ELEMENT: ");
    scanf("%d", &head->data);
    head->next = NULL;

    for (int i = 1; i < n; i++) {
        p->next = (struct node*)malloc(sizeof(struct node));
        p = p->next;
        printf("ENTER THE ELEMENT: ");
        scanf("%d", &p->data);
        p->next = NULL;
    }

    printf("Original List:\n");
    traverselinkedlist(head);

    head = reverselinkedlist(head);

    printf("\nReversed List:\n");
    traverselinkedlist(head);

    return 0;
}
