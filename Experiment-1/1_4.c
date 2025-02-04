#include <stdio.h>
#include <stdlib.h>

void sortArray(int *ptr, int n) {
    for (int i = 0; i < n -1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (ptr[j] < ptr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = ptr[min];
            ptr[min] = ptr[i];
            ptr[i] = temp;
        }
        
    }
    
}

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

    sortArray(ptr, n);

    for (int k = 0; k < n; k++)
    {
        printf("%d ", ptr[k]);
    }
    
}