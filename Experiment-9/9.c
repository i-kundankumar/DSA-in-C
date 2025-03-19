/* WAP Write the following menu driven program for the binary search tree
----------------------------------------
Binary Search Tree Menu
----------------------------------------
0. Quit
1. Create
2. In-Order Traversal
3. Pre-Order Traversal
4. Post-Order traversal
5. Search
6. Find Smallest Element
7. Find Largest Element
8. Deletion of Tree
----------------------------------------
Enter your choice: */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}


void inOrder(struct node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}


void preOrder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

struct node *searchNode(struct node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return searchNode(root->left, data);
    return searchNode(root->right, data);
}

struct node *findSmallest(struct node *root)
{
    if (root == NULL || root->left == NULL)
        return root;
    return findSmallest(root->left);
}

struct node *findLargest(struct node *root)
{
    if (root == NULL || root->right == NULL)
        return root;
    return findLargest(root->right);
}

struct node *deleteTree(struct node *root)
{
    if (root != NULL)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
    return NULL;
}

void displayMenu()
{
    printf("\n----------------------------------------\n");
    printf("Binary Search Tree Menu\n");
    printf("----------------------------------------\n");
    printf("0. Quit\n");
    printf("1. Create\n");
    printf("2. In-Order Traversal\n");
    printf("3. Pre-Order Traversal\n");
    printf("4. Post-Order Traversal\n");
    printf("5. Search\n");
    printf("6. Find Smallest Element\n");
    printf("7. Find Largest Element\n");
    printf("8. Deletion of Tree\n");
    printf("----------------------------------------\n");
    printf("Enter your choice: ");
}

int main()
{
    struct node *root = NULL;
    int choice, data;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting program.\n");
            break;
        case 1:
            printf("Enter elements to insert:\n");
            scanf("%d", &data);
            root = insertNode(root, data);
            
            break;
        case 2:
            printf("In-Order Traversal: ");
            if (root == NULL)
                printf("Tree is empty.");
            else
                inOrder(root);
            printf("\n");
            break;
        case 3:
            printf("Pre-Order Traversal: ");
            if (root == NULL)
                printf("Tree is empty.");
            else
                preOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Post-Order Traversal: ");
            if (root == NULL)
                printf("Tree is empty.");
            else
                postOrder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter value to search: ");
            scanf("%d", &data);
            struct node *result = searchNode(root, data);
            printf(result ? "Value found.\n" : "Value not found.\n");
            break;
        case 6:
        {
            struct node *smallest = findSmallest(root);
            printf(smallest ? "Smallest element: %d\n" : "Tree is empty.\n",
                   smallest ? smallest->data : 0);
            break;
        }
        case 7:
        {
            struct node *largest = findLargest(root);
            printf(largest ? "Largest element: %d\n" : "Tree is empty.\n",
                   largest ? largest->data : 0);
            break;
        }
        case 8:
            root = deleteTree(root);
            printf("Tree deleted.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    if (root != NULL)
        deleteTree(root);
    return 0;
}
