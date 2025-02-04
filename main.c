#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* newNode(int data){
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(struct Node* n){
    while (n!= NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    
}


void main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    head = newNode(1);
    second = newNode(2);
    third = newNode(3);

    head->next = second;
    second->next = third;
    printList(head);
}
