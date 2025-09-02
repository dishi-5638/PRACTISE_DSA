#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node Structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* addNode(struct Node* head, int p, int x) {
    struct Node *temp, *tp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
    tp = head;

    // Move tp to p-th node
    while (p != 0 && tp != NULL) {
        tp = tp->next;
        p--;
    }

    // If tp is NULL, position is out of bounds
    if (tp == NULL) return head;

    // Insert temp after tp
    temp->next = tp->next;
    if (tp->next != NULL)  // Important check
        tp->next->prev = temp;
    tp->next = temp;
    temp->prev = tp;

    return head;
}


// Function to print the DLL
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf("<->");
        temp = temp->next;
    }
    printf("\n");
}

// Main Driver Code
int main() {
    // Create a sample DLL: 2<->4<->5
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 2;
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->next = second;
    head->prev = NULL;
    second->data = 4;
    second->next = third;
    second->prev = head;
    third->data = 5;
    third->next = NULL;
    third->prev = second;

    printf("Original List: ");
    printList(head);

    int p = 2, x = 6;
    head = addNode(head, p, x);

    printf("Updated List: ");
    printList(head);

    return 0;
}
