#include <stdio.h>

struct cgpa
{
    float sgpa1, sgpa2;
};

float calCgpa(struct cgpa sem){
    return (sem.sgpa1 + sem.sgpa2) / 2;
}

void main()
{

    struct cgpa sem;
    printf("Enter SGPA of Semester 1: ");
    scanf("%f", &sem.sgpa1);

    printf("Enter SGPA of Semester 2: ");
    scanf("%f", &sem.sgpa2);

    float result = calCgpa(sem);
    printf("Your CGPA is %f", result);
}