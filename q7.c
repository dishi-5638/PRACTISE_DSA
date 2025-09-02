#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Tumhara function
struct Node* removeDuplicates(struct Node* head);

struct Node* removeDuplicates(struct Node* head) {
    struct Node *temp = head;
    struct Node *prev, *curr;

    while (temp != NULL && temp->next != NULL) {
        prev = temp;
        curr = temp->next;

        while (curr != NULL) {
            if (temp->data == curr->data) {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        temp = temp->next;
    }
    return head;
}


// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Linked List: 5 -> 2 -> 3 -> 2 -> 4
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 5;
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));

    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 2;
    fourth->next = fifth;
    fifth->data = 4;
    fifth->next = NULL;

    printf("Original List: ");
    printList(head);

    head = removeDuplicates(head);  // Tumhara function call

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
