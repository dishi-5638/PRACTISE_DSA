#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to display linked list
void display(struct Node *head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to check if linked list is palindrome
int isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return 1; // Single node or empty list is always palindrome

    // Step 1: Find first middle
    struct Node* slow = head;
    struct Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        if (fast != NULL)
            slow = slow->next;
    }

    // Step 2: Reverse second half
    struct Node *revHead = slow->next;
    struct Node *prev = NULL, *curr = NULL;

    while (revHead != NULL) {
        curr = revHead->next;
        revHead->next = prev;
        prev = revHead;
        revHead = curr;
    }
    revHead = prev; // New head of reversed half

    // Step 3: Compare first and second half
    struct Node *temp1 = head, *temp2 = revHead;
    while (temp2 != NULL) { // Only check second half
        if (temp1->data != temp2->data)
            return 0; // Not palindrome
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 1; // Palindrome
}

int main() {
    // Sample Linked List: 1->2->3->3->2->1
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
    fourth->data = 3;
    fourth->next = fifth;
    fifth->data = 2;
    fifth->next = sixth;
    sixth->data = 1;
    sixth->next = NULL;

    display(head);
    
    if (isPalindrome(head))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
