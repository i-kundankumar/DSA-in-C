#include <stdio.h>
#include <string.h>

void reverseString(char *str)
{
    char *start, *end, ch;

    start = str;
    end = str + strlen(str) - 1;

    while (start < end)
    {
        ch = *start;
        *start = *end;
        *end = ch;

        start++;
        end--;
    }
    
}

int main()
{
    char str[] = "DSA_LAB";

    printf("Original String: %s\n", str);
    reverseString(str);
    printf("Reversed String: %s\n", str);

    return 0;
}
