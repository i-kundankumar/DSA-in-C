#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CartItem
{
    char name[50];
    int quantity;
    float price;
    struct CartItem *next;
};

struct CartItem *head = NULL;

void addItem(char name[], int quantity, float price)
{
    struct CartItem *newItem = (struct CartItem *)malloc(sizeof(struct CartItem));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->next = NULL;

    if (head == NULL)
    {
        head = newItem;
    }
    else
    {
        struct CartItem *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newItem;
    }
    printf("Item added: %s (x%d) - INR %.2f\n", name, quantity, price);
}

void removeItem(char name[])
{
    struct CartItem *temp = head;
    struct CartItem *prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Item not found!\n");
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
    printf("Item removed: %s\n", name);
}

void updateQuantity(char name[], int quantity)
{
    struct CartItem *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            temp->quantity = quantity;
            printf("Updated quantity: %s (x%d)\n", name, quantity);
            return;
        }
        temp = temp->next;
    }
    printf("Item not found!\n");
}

void displayCart()
{
    if (head == NULL)
    {
        printf("Your cart is empty!\n");
        return;
    }

    struct CartItem *temp = head;
    printf("\nShopping Cart:\n");
    printf("---------------------------------\n");
    while (temp != NULL)
    {
        printf("%s (x%d) - INR %.2f\n", temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
    printf("---------------------------------\n");
}

void calculateTotal()
{
    float total = 0;
    struct CartItem *temp = head;

    while (temp != NULL)
    {
        total += temp->price * temp->quantity;
        temp = temp->next;
    }

    printf("Total Cost: INR %.2f\n", total);
}

int main()
{
    int choice, quantity;
    char name[50];
    float price;

    while (1)
    {
        printf("\n1. Add Item\n2. Remove Item\n3. Update Quantity\n4. Display Cart\n5. Calculate Total\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter item name: ");
            scanf(" %[^\n]s", name); 
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%f", &price);
            addItem(name, quantity, price);
            break;
        case 2:
            printf("Enter item name to remove: ");
            scanf(" %[^\n]s", name);
            removeItem(name);
            break;
        case 3:
            printf("Enter item name to update: ");
            scanf(" %[^\n]s", name);
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            updateQuantity(name, quantity);
            break;
        case 4:
            displayCart();
            break;
        case 5:
            calculateTotal();
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
