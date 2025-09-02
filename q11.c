#include <stdio.h>
#define MAX 100  // Maximum size of stack
// stack using array without use of global variable
// Stack structure
typedef struct {
    int top;
    int arr[MAX];
} Stack;

// Function to initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;   
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Function to get the top element of the stack without popping it
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

// Function to display the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);
    
    printf("Popped element: %d\n", pop(&s));
    display(&s);
    
    printf("Top element: %d\n", peek(&s));
    
    return 0;
}
