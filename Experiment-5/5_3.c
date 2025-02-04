#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void createList(struct Node **head, int n)
{
    struct Node *newNode, *temp;
    int data;

    if (n <= 0)
    {
        printf("List cannot be created with 0 or negative nodes.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode = (struct Node *)malloc(sizeof(struct Node)); 
        newNode->data = data;
        newNode->next = *head;

        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            temp->next = newNode;
        }

        temp = newNode;
    }
    temp->next = *head;
}

void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main()
{
    struct Node *head = NULL; 
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createList(&head, n);
    displayList(head);

    return 0;
}
