#include<stdio.h>
#include <stdlib.h>


struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* createNode(int coeff, int exp) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff= coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int coeff, int exp) {
    struct Node *newNode = createNode(coeff, exp);
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

void displayPolynomial(struct Node* head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx%d", temp->coeff, temp->exp);
        if (temp -> next != NULL && temp->next->coeff >= 0)
        {
            printf(" + ");
        }
        temp = temp->next;
        }
        printf("\n");
}



void main()
{
    struct Node *poly = NULL;

    insertNode(&poly, 6, 3);
    insertNode(&poly, -8, 2);
    insertNode(&poly, 2, 1);
    insertNode(&poly, 5, 0);

    printf("Polynomial Expression: ");
    displayPolynomial(poly);
}