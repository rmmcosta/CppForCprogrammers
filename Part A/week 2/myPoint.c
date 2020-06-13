#include <stdio.h>

typedef struct Point
{
    int x, y;
} Point;


Point sum(Point p1, Point p2)
{
    Point sum;
    sum.x = p1.x + p2.x;
    sum.y = p1.y + p2.y;
    return sum;
}

void sumToPoint(Point *p1, Point p2) {
    p1->x += p2.x;
    p1->y += p2.y;
}

int main()
{
    Point p1, p2;
    p1.x = 3;
    p1.y = 3;
    p2.x = 10;
    p2.y = 6;
    printf("point p1 -> (%d, %d), point p2 -> (%d, %d)\n", p1.x, p1.y, p2.x, p2.y);
    Point sumPoint = sum(p1, p2);
    printf("sum point -> (%d, %d)\n", sumPoint.x, sumPoint.y);
    sumToPoint(&p1, p2);
    printf("sum to point p1 -> (%d, %d)\n", p1.x, p1.y);
    return 0;
}
