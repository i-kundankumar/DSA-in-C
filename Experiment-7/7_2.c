#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int isEmpty()
{
    return front == NULL;
}

void enqueue(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode)
    {
        printf("Heap overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d is enqueued\n", data);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        printf("%d is dequeued\n", temp->data);
        free(temp);
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Peek element is %d\n", front->data);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct node *temp = front;
        printf("Queue contents: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main()
{
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Check if queue is empty\n");
        printf("2. Display the content of queue\n");
        printf("3. Enqueue\n");
        printf("4. Dequeue\n");
        printf("5. Peek\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isEmpty())
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 4:
            dequeue();
            break;
        case 5:
            peek();
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}