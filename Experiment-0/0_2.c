#include<stdio.h>

int findLargest(int num[], int l) {
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
    printf("Largest Number is: %d", largest);
}