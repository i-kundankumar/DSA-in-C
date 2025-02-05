/* WAP Write a menu driven program to perform the following 
operations of a stack using linked list by using suitable user defined 
functions for each case.
a) Check if the stack is empty
b) Display the contents of stack
c) Push d) Pop */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Stack overflow\n");
        return;
    }
    newNode->value = value;
    newNode->next = top;
    top = newNode;
    printf("%d Pushed to Stack", value);
}

void pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
    } else {
        struct node *temp = top;
        top = top->next;
        printf("Popped %d from stack\n", temp->value);
        free(temp);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        struct node *temp = top;
        printf("Stack: ");
        while (temp != NULL) {
            printf("%d ", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main() {
    int choice, value, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Check if stack is empty\n");
        printf("2. Display the content of stack\n");
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
                printf("Enter the values you want to push: ");
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