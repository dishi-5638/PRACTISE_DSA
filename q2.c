#include <stdio.h>
#include <stdlib.h>

// Linked list ka node structure
struct Node {
    int data;
    struct Node* next;
};

// Tumhe ye function likhna hai
int findKthFromEnd(struct Node* head, int k);

// Print linked list (Optional)
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int findKthFromEnd(struct Node* head, int k){
    struct Node*temp = head;
    struct Node *tp = head;
    int count =1;
    while(temp->next!=NULL)
    {
        count++;
        temp = temp->next;
    }
    int n = count;
    if(k>n)
    return -1;
    else{
        for(int i =1;i<n-k+1;i++){
tp = tp->next;
        }
    }
    return tp->data;
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

    int k = 2;  // Example: 2nd node from end
    int result = findKthFromEnd(head, k);
    printf("Kth Node from End is: %d\n", result);

    return 0;
}
