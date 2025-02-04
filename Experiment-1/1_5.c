#include <stdio.h>
#include <stdlib.h>

void sortArray(int a, int b, int *ptr, int n)
{
    int count =0;
    if (a>b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("Number is: ");
    for (int i = 0; i < n; i++)
    {
        
        if (ptr[i] >= a && ptr[i] <= b)
        {
            printf("%d ", ptr[i]);
            count++;
        }
    }
    printf("and count is: %d", count);
}

void main()
{
    int n, *ptr, a, b;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the number to find between(a, b): ");
    scanf("%d %d", &a, &b);

    ptr = (int *)malloc(n * sizeof(int));

    printf("Enter the element of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    sortArray(a, b, ptr, n);
}