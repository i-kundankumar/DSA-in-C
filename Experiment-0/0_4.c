#include <stdio.h>

void main()
{
    int a, b;
    char op;

    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Enter Operator(+,-,*,/): ");
    scanf(" %c", &op);

    switch (op)
    {
    case '+':
        printf("Addition: %d", a + b);
        break;
    case '-':
        printf("Subtraction: %d", a - b);
        break;
    case '*':
        printf("Multiplication: %d", a * b);
        break;
    case '/':
        printf("Division: %d", a / b);
        break;

    default:
        printf("Invalid Operator");
        break;
    }
}