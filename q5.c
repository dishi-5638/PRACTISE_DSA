#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert x at the end (Ye tumhara kaam hai)
struct Node* insertAtEnd(struct Node* head, int x);


void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* insertAtEnd(struct Node* head, int x){
    struct Node*temp,*tp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next =NULL;
    tp = head;
    if (head == NULL) {
        head = temp;  // List khali hai to new node hi head banegi
        return head;
    }

    while(tp->next!=NULL){
        tp = tp->next;
    }
    tp->next=temp;
    return head;

}

int main() {
    // Creating sample linked list: 1->2->3
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    int x = 4; // Value to insert

    head = insertAtEnd(head, x);

    printf("Linked List after insertion: ");
    printList(head);

    return 0;
}
// insertion at end