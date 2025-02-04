#include <stdio.h>

int main()
{
    int arr[] = {14, 54, 87, 46, 35};
    int *ptr = arr;                       

    printf("Array elements are: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr+i));
    }

    return 0;
}
