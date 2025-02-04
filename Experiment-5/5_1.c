#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* createNode(int n) {
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;


    for (int i = 0; i < n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the data of Node %d: ",i);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;
        
        if (head == NULL)
        {
            head = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
        }
        temp = newNode;
        }

        return head;
}

void displayList(struct Node* head)
{
    struct Node *temp = head;

    if (temp == NULL)
    {
        printf("List is empty");
        return;
    }
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main()
{
    int n;
    struct Node *head = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    head = createNode(n);

    displayList(head);
}


