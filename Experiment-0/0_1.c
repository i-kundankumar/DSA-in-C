#include <stdio.h>
#include <string.h>

void main()
{
    char rollNumber[20];
    int l;

    printf("Enter your roll number: ");
    scanf("%s", rollNumber);

    l = strlen(rollNumber);

    for (int i = 0; i < l; i++)
    {
        if ((i + 1) % 2 != 0)
        {
            printf("\nDigits at odd places: %c", rollNumber[i]);
        }

        if ((i + 1) % 2 == 0)
        {
            printf("\nDigits at even places: %c", rollNumber[i]);
        }
    }
}