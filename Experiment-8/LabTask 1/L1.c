#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *newNode(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head = temp;
    return head;
}

void insertAtLast(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

struct node* reverseKGroup(struct node *head, int k)
{
    struct node *current = head;
    struct node *next = NULL;
    struct node *prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = reverseKGroup(next, k);
    }

    return prev;
}

void Print(struct node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL");
}

void main()
{
    struct node *head = NULL;
    int rollNumber = 2304100;
    int k = 2;
    while (rollNumber > 0)
    {
        int digit = rollNumber % 10;
        if (head == NULL)
        {
            head = newNode(head, digit);
        }
        else
        {
            insertAtLast(head, digit);
        }
        rollNumber /= 10;
    }

    Print(head);

    head = reverseKGroup(head, k);
    printf("\nModified: \n");
    Print(head);
}