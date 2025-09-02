#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list (Ye tumhara kaam hai likhna)
struct Node* reverseList(struct Node* head);

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;   // Next node store karo
        curr->next = prev;   // Current ka next ulta kar do
        prev = curr;         // Prev ko aage badhao
        curr = next;         // Curr ko aage badhao
    }

    return prev;  // New head ye hoga
}


int main() {
    // Sample Linked List: 1->2->3->4->5
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));

    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = fifth;
    fifth->data = 5;
    fifth->next = NULL;

    struct Node* newHead = reverseList(head);

    // Printing reversed list
    struct Node* temp = newHead;
    printf("Reversed List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
