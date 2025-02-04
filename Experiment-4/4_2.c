#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int degree;      
    int coefficient; 
} Term;

void createPolynomial(Term poly[], int *size)
{
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", size);

    printf("Enter the terms as degree and coefficient (highest to lowest degree):\n");
    for (int i = 0; i < *size; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly[i].degree, &poly[i].coefficient);
    }
}

void displayPolynomial(Term poly[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i > 0 && poly[i].coefficient > 0)
        {
            printf(" + ");
        }
        printf("%dx^%d", poly[i].coefficient, poly[i].degree);
    }
    printf("\n");
}

void addPolynomials(Term poly1[], int size1, Term poly2[], int size2, Term result[], int *resultSize)
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (poly1[i].degree > poly2[j].degree)
        {
            result[k++] = poly1[i++];
        }
        else if (poly1[i].degree < poly2[j].degree)
        {
            result[k++] = poly2[j++];
        }
        else
        {
            result[k].degree = poly1[i].degree;
            result[k].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            i++;
            j++;
            if (result[k].coefficient != 0)
            {
                k++;
            }
        }
    }

    while (i < size1)
    {
        result[k++] = poly1[i++];
    }

    while (j < size2)
    {
        result[k++] = poly2[j++];
    }

    *resultSize = k;
}

int main()
{
    Term poly1[20], poly2[20], result[40]; 
    int size1, size2, resultSize;


    printf("Creating the first polynomial:\n");
    createPolynomial(poly1, &size1);
    printf("First Polynomial: ");
    displayPolynomial(poly1, size1);

    printf("Creating the second polynomial:\n");
    createPolynomial(poly2, &size2);
    printf("Second Polynomial: ");
    displayPolynomial(poly2, size2);

    addPolynomials(poly1, size1, poly2, size2, result, &resultSize);

    printf("Resultant Polynomial after addition: ");
    displayPolynomial(result, resultSize);

    return 0;
}
