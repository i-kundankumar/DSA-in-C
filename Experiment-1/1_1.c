#include<stdio.h>

int findLargest(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int findSmallest(int arr[], int n, int l)
{
    int min = l;
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

void main()
{
    int arr[] = {12, 34, 56, 66, 45};
    int n = 5;

    int largest = findLargest(arr, n);
    printf("Largest number is: %d", largest);
    int smallest = findSmallest(arr, n, largest);
    printf("\nSmallest Number is: %d", smallest);
}