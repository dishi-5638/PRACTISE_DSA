#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to rearrange linked list
struct Node* oddEvenList(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head; // Edge case: empty list or single node list

    struct Node* odd = head;
    struct Node* even = head->next;
    struct Node* evenHead = even; // Store head of even list

    while (even != NULL && even->next != NULL) {
        odd->next = even->next; // Link odd nodes
        odd = odd->next;

        even->next = odd->next; // Link even nodes
        even = even->next;
    }

    odd->next = evenHead; // Attach even list to odd list end
    return head;
}

// Function to print linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver Code
int main() {
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

    printf("Original List:\n");
    display(head);

    head = oddEvenList(head);

    printf("Reordered List:\n");
    display(head);

    return 0;
}
