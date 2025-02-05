/* WAP Write a menu driven program to perform the following operations of a stack using
array by using suitable user defined functions for each case.
a) Check if the stack is empty
b) Display the contents of stack
c) Push d) Pop */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = value;
        printf("%d Pushed to Stack\n", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
    } else {
        printf("Popped %d from stack\n", stack[top--]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void main() {
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Check if stack is empty\n");
        printf("2. Display stack contents\n");
        printf("3. Push\n");
        printf("4. Pop\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 4:
                pop();
                break;
            case 5:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}