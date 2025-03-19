#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

void init(struct Stack *stack)
{
    stack->top = NULL;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == NULL;
}

void push(struct Stack *stack, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack.\n", value);
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
        return -1;
    }
    struct Node *temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *current = stack->top;
    printf("Stack: ");
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Stack stack;
    init(&stack);
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Push\n2. Pop\n3. Check Empty\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            printf("Popped: %d\n", pop(&stack));
            break;
        case 3:
            printf("Stack is %s\n", isEmpty(&stack) ? "empty" : "not empty");
            break;
        case 4:
            display(&stack);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
