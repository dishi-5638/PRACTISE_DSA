// implement a queue using linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void display() {
    struct node *temp = front;
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct node *temp = front;
        printf("Dequeued element: %d\n", front->data);
        front = front->next;
        free(temp);

        // If front becomes NULL, update rear as well
        if (front == NULL) {
            rear = NULL;
        }
    }
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element is %d\n", front->data);
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    
    display();
    
    dequeue();
    
    display();
    
    peek();
    
    return 0;
}
