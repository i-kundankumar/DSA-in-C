#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printMthFromLast(struct Node *head, int m)
{
    struct Node *mainPtr = head;
    struct Node *refPtr = head;
    int count = 0;

    while (count < m)
    {
        if (refPtr == NULL)
        {
            printf("The list has fewer than %d nodes.\n", m);
            return;
        }
        refPtr = refPtr->next;
        count++;
    }

    while (refPtr != NULL)
    {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }

    printf("The %d-th node from the last is: %d\n", m, mainPtr->data);
}

int main()
{
    struct Node *head = NULL;
    int n, data, m;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Enter the value of m (position from the last): ");
    scanf("%d", &m);

    printMthFromLast(head, m);

    return 0;
}
