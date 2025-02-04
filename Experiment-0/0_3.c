#include <stdio.h>

int findLargest(int num[], int l)
{
    int max = 0;
    for (int i = 0; i < l; i++)
    {
        if (max < num[i])
        {
            max = num[i];
        }
    }
    return max;
}

int findSmallest(int num[], int l, int max)
{
    int min = max;
    for (int i = 0; i < l; i++)
    {
        if (min > num[i])
        {
            min = num[i];
        }
        
    }
    return min;
}

void main()
{
    int num[20];
    int l = 3;

    printf("Enter three numbers: ");
    for (int i = 0; i < l; i++)
    {
        scanf("%d", &num[i]);
    }

    int largest = findLargest(num, l);
    int smallest = findSmallest(num, l, largest);
    printf("Largest Number is: %d", largest);
    printf("\nSmallest Number is: %d", smallest);
}