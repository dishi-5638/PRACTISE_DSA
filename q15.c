#include <stdio.h>
#include <stdlib.h>
// reverse a ll
struct Node {
    int data;
    struct Node* next;
};

struct Node *reverse(struct Node *head){
    struct Node *prev = NULL;
    struct Node *curr = NULL;
    while(head != NULL){
        curr = head->next;
        head->next = prev;
        prev = head;
        head = curr;
    }
    head = prev;
    return head;

}

void display(struct Node *head){
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    // Sample Linked List: 1->2->3->4->5->6
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* sixth = (struct Node*)malloc(sizeof(struct Node));

    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->next = sixth;
    sixth->data = 6;
    sixth->next = NULL;
display(head);
   head = reverse(head);
   printf("\n");
   display(head);

    return 0; }