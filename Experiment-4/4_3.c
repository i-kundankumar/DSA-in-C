#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int row;         
    int col;           
    int value;         
    struct Node *next; 
};

struct Node *createNode(int row, int col, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **head, int row, int col, int value)
{
    struct Node *newNode = createNode(row, col, value);
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

void displaySparseMatrix(struct Node *head)
{
    printf("Row\tCol\tValue\n");
    while (head != NULL)
    {
        printf("%d\t%d\t%d\n", head->row, head->col, head->value);
        head = head->next;
    }
}

void displayMatrix(struct Node *head, int rows, int cols)
{
    int matrix[rows][cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }

    while (head != NULL)
    {
        matrix[head->row][head->col] = head->value;
        head = head->next;
    }


    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    struct Node *sparseMatrix = NULL;
    int rows, cols, numNonZero;


    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);


    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numNonZero);


    printf("Enter the row, column, and value of the non-zero elements:\n");
    for (int i = 0; i < numNonZero; i++)
    {
        int row, col, value;
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &row, &col, &value);
        insertNode(&sparseMatrix, row, col, value);
    }

    printf("\nSparse Matrix Representation:\n");
    displaySparseMatrix(sparseMatrix);

    printf("\nOriginal Matrix:\n");
    displayMatrix(sparseMatrix, rows, cols);

    return 0;
}
