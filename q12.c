// queue using array without global variables

#include <stdio.h>
#define MAX 100 

typedef struct {
    int front;
    int rear;
    int queue[MAX];
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;   
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    if (q->front == -1) {  // First element being inserted
        q->front = 0;
    }
    q->queue[++(q->rear)] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int dequeuedValue = q->queue[q->front]; // First store the value
    q->front++;  // Move front ahead
    
    // Reset queue if last element is dequeued
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    
    return dequeuedValue;
}

int peek(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->queue[q->front];
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(&q);
    
    printf("Dequeued element is: %d\n", dequeue(&q));
    display(&q);
    
    printf("Peek element: %d\n", peek(&q));
    
    return 0;
}
