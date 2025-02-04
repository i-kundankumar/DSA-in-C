#include<stdio.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int a, b;

    printf("Enter a first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Before Swapping: \n");
    printf("First number: %d\nSecond number: %d", a, b);

    swap(&a, &b);

    printf("\nAfter Swapping:\n");
    printf("First number: %d\nSecond number: %d", a, b);
}