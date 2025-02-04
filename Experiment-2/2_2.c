#include<stdio.h>
#include<math.h>

struct Point {
    int x;
    int y;
};

float calculateArea(struct Point a, struct Point b, struct Point c) {
    return fabs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

void main() {
    struct Point a, b, c;

    printf("Enter coordinates of point A (x y): ");
    scanf("%d %d", &a.x, &a.y);

    printf("Enter coordinates of point B (x y): ");
    scanf("%d %d", &b.x, &b.y);

    printf("Enter coordinates of point C (x y): ");
    scanf("%d %d", &c.x, &c.y);

    float area = calculateArea(a, b, c);
    printf("Area of the triangle: %.2f\n", area);
}