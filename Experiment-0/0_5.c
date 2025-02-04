#include<stdio.h>

int findFact(int num)
{
    int fact = 1;
    for (int  i = 1; i <= num; i++)
    {
        fact *= i;
    }
    return fact;
}

void main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 0)
    {
        printf("Result: %d", findFact(num));
    } else {
        printf("Enter a positive number: ");
        scanf("%d", &num);
    }
}