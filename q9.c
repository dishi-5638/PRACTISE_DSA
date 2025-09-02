#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create Doubly Linked List from array
struct Node* constructDLL(int arr[], int n);

struct Node* constructDLL(int arr[], int n) {
    if (n == 0) return NULL;  // Better practice

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;
    head->prev = NULL;

    struct Node* temp = head;

    for (int i = 1; i < n; i++) {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = arr[i];
        newnode->next = NULL;
        newnode->prev = temp;
        temp->next = newnode;
        temp = newnode;
    }

    return head;
}


// Function to print Doubly Linked List
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);  // Size of array
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Array input
    }

    struct Node* head = constructDLL(arr, n);
    printList(head);

    return 0;
}


