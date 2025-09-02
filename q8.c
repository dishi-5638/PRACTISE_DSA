#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create loop if c > 0
void createLoop(struct Node* head, int c) {
    if (c == 0) return;
    struct Node* temp = head;
    struct Node* loopNode = NULL;
    int count = 1;
    while (temp->next != NULL) {
        if (count == c) loopNode = temp;
        temp = temp->next;
        count++;
    }
    if (loopNode) temp->next = loopNode; // Creating loop
}

// Function to count nodes in loop
int countNodesInLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Detect loop using Floyd’s cycle detection
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {  // Loop detected
            // Now count the loop length
            int count = 1;
            struct Node* temp = slow;
            while (temp->next != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0; // No loop
}

// Main / Driver code
int main() {
    int n, c;
    scanf("%d %d", &n, &c);  // Number of nodes and c value
    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Input nodes
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Create loop if c > 0
    createLoop(head, c);

    // Find loop length
    int loopLength = countNodesInLoop(head);
    printf("%d\n", loopLength);

    return 0;
}
