#include <stdio.h>

int findSecondLargest(int arr[], int n)
{
    int first = 0, second = 0;
    for (int i = 0; i <= n; i++)
    {
        if (first < arr[i])
        {
            first = arr[i];
        } 
    }
    for (int i = 0; i <= n; i++)
    {
        if (second < arr[i] && arr[i] != first)
        {
            second = arr[i];
        }
    }
    return second;
}
    

void main()
{
    int arr[] = {10, 20, 4, 45, 99};
    int n = 5;
    printf("The Second Largest Number is: %d", findSecondLargest(arr, n));
}
