#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createDoublyLinkedList(int n)
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;

    for (int i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return head;
        }

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
        }
        temp = newNode;
    }

    return head;
}

void displayDoublyLinkedList(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("The doubly linked list is empty.\n");
        return;
    }

    printf("Doubly linked list: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node *addNode(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct Node *deleteNode(struct Node *head, int value)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return head;
    }


    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", value);
        return head;
    }


    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next; 
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node with value %d deleted.\n", value);

    return head;
}

int main()
{
    int n, data, value;
    struct Node *head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = createDoublyLinkedList(n);
    displayDoublyLinkedList(head);

    printf("Enter data to add a new node: ");
    scanf("%d", &data);
    head = addNode(head, data);
    printf("After adding a new node:\n");
    displayDoublyLinkedList(head);

    printf("Enter value of the node to delete: ");
    scanf("%d", &value);
    head = deleteNode(head, value);
    printf("After deleting the node:\n");
    displayDoublyLinkedList(head);

    return 0;
}