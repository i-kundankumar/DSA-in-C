#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};


void traverseList(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("The list elements are: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int isEmpty(struct Node *head)
{
    return head == NULL;
}


void insertNode(struct Node **head, int data, int position)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteNode(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = *head;

    if (position == 1)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node *prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of bounds.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;
    printf("1. Traverse the list\n");
    printf("2. Check if the list is empty\n");
    printf("3. Insert a node\n");
    printf("4. Delete a node\n");
    printf("5. Count the total number of nodes\n");
    do
    {
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traverseList(head);
            break;

        case 2:
            if (isEmpty(head))
            {
                printf("The list is empty.\n");
            }
            else
            {
                printf("The list is not empty.\n");
            }
            break;

        case 3:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            printf("Enter the position to insert the node: ");
            scanf("%d", &position);
            insertNode(&head, data, position);
            break;

        case 4:
            printf("Enter the position to delete the node: ");
            scanf("%d", &position);
            deleteNode(&head, position);
            break;

        case 5:
            printf("The total number of nodes is: %d\n", countNodes(head));
            break;

        case 6:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
