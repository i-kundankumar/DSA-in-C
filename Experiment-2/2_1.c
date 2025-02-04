#include<stdio.h>

struct distance
{
    int km;
    int m;
};

struct distance addDistance(struct distance d1, struct distance d2)
{
    struct distance result;
    result.km = d1.km + d2.km;
    result.m = d1.m + d2.m;
    if (result.m >= 1000)
    {
        result.km += result.m / 1000;
        result.m %= 1000;
    }

    return result;
};

void main()
{
    struct distance d1, d2, result;
    printf("Enter first distance(in Km - m): ");
    scanf("%d %d", &d1.km, &d1.m);
    printf("Enter second distance(in km - m): ");
    scanf("%d %d", &d2.km, &d2.m);
    result = addDistance(d1, d2);
    if (result.m == 0)
    {
        printf("Addition of two distance is %d km", result.km);
    } else {
        printf("Addition of two distance is %d km %d m", result.km, result.m);
    }
    
    
}