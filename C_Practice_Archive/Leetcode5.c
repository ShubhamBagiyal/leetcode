#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}node;
node* mergeTwoLists(node* head1,node* head2) {         //this function returns merged head by comparing and taking small one and connects accordibgly
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    if(head1->data<head2->data){
        head1->next=mergeTwoLists(head1->next,head2);
        return head1;
    }
    else{
        head2->next=mergeTwoLists(head1,head2->next);
        return head2;
    }
}
void printList(node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    // Creating first sorted linked list: 1 -> 3 -> 5
    node* head1 =(node*)malloc(sizeof(node));
    node* second =(node*)malloc(sizeof(node));
    node* third =(node*)malloc(sizeof(node));
    head1->data=1;
    head1->next = second;
    second->data=3;
    head1->next->next = third;
    third->data=5;

    // Creating second sorted linked list: 2 -> 4 -> 6
    node* head2 =(node*)malloc(sizeof(node));
    node* secon =(node*)malloc(sizeof(node));
    node* thir =(node*)malloc(sizeof(node));
    head2->data=2;
    head2->next = secon;
    secon->data=4;
    head2->next->next = thir;
    thir->data=6;

    printf("List 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);
    node* mergedHead = mergeTwoLists(head1, head2);

    printf("Merged List: ");
    printList(mergedHead);

    return 0;
}
