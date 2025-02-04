#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, *ptr;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));

    
        printf("Enter the element of the array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &ptr[i]);
        }

        printf("Reversed element of the array is: ");

        for (int i = n-1; i >= 0; i--)
        {
            printf("%d ", ptr[i]);
        }

        free(ptr);
    
}