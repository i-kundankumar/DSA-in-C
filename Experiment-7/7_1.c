#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int data) 
{
    if (rear == MAX)
    {
        printf("Queue is Full\n");
    } else {
        if (front == 0 && rear == 0)
        {
            front = 1;
            rear = 1;
        } else {
            rear++;
        }
        queue[rear] = data;
        printf("%d is enqueued", data);
    }
    
}

void dequeue()
{
    if (front == 0)
    {
        printf("Queue UnderFlow");
    } else {
        printf("%d is dequeued", queue[front]);
        if (front==rear)
        {
            front = 1;
            rear = 1;
        } else {
            front++;
        }
    }
}

void peek()
{
    if (front == 0)
    {
        printf("Queue is Empty");
    } else {
        printf("Peek element is %d", queue[front]);
    }
}

void isEmpty()
{
    if (front == 0)
    {
        printf("Queue is empty");
    } else {
        printf("Queue is not empty");
    }
}

void isFull()
{
    if (rear == MAX)
    {
        printf("Queue is Full");
    } else {
        printf("Queue is not Full");
    }
}

void display()
{
    if (front == 0)
    {
        printf("Queue is Empty");
    } else {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}

void main(){
    int choice, value, n;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Check if queue is empty\n");
        printf("2. Display the content of stack\n");
        printf("3. Enqueue\n");
        printf("4. Dequeue\n");
        printf("5. check if queue is full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            isEmpty();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter the values you want to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 4:
            dequeue();
            break;

        case 5:
            isFull();
            break;
        case 6:
            printf("Exiting...");
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}