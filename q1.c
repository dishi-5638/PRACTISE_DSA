#include <stdio.h>
#include <stdlib.h>
//first code changed
// Node structure
struct Node {
    int data;
    struct Node* next;
};

// You have to complete this function
struct Node* constructLL(int arr[], int n);

// Function to print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("\n");
}

struct Node* constructLL(int arr[], int n){
    if(n==0) return NULL;
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;
    struct Node *temp= head;
    for(int i =1;i<n;i++){
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = arr[i];
        newnode->next= NULL;
        temp->next =newnode;
        temp=temp->next;


    }
    return head;

}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = constructLL(arr, n);
    printList(head);

    return 0;
}
//Given an array of integer arr. Your task is to construct the linked list from arr & return the head of the linked list