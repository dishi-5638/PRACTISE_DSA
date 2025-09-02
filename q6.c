#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to remove duplicates (Ye tumhara kaam hai)
struct Node* removeDuplicates(struct Node* head);

struct Node* removeDuplicates(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            // Duplicate mila, next node hatao
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
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
    // Sample sorted linked list: 1->1->2->3->3->4
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));
    struct Node* sixth = (struct Node*)malloc(sizeof(struct Node));

    head->next = second;
    second->data = 1;
    second->next = third;
    third->data = 2;
    third->next = fourth;
    fourth->data = 3;
    fourth->next = fifth;
    fifth->data = 3;
    fifth->next = sixth;
    sixth->data = 4;
    sixth->next = NULL;

    printf("Original List: ");
    printList(head);

    head = removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
