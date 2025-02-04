#include<stdio.h>
#include<stdlib.h>

int find(int *ptr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (target == ptr[i])
        {
            return i;
        }
    }
    return 0;
}

void main()
{
    int n, *ptr, target;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    

    ptr = (int *)malloc(n * sizeof(int));

    
        printf("Enter the element of the array: ");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &ptr[i]);
        }

        printf("Enter the target element: ");
        scanf("%d", &target);

        int result = find(ptr, n, target);
        if (result != 0)
        {
            printf("Target is found at index %d", result);
        }
        else {
            printf("Target not found!");
        }
        
                
    
}