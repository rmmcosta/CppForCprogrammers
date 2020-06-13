/* c program to swap 
*  2 ints
*/

#include <stdio.h>

void swapInt(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void swapDouble(double *first, double *second)
{
    double temp = *first;
    *first = *second;
    *second = temp;
}

int main()
{
    int first = 0, second = 0;
    printf("Please input 2 numbers. First: ");
    scanf("%d", &first);
    printf("Second: ");
    scanf("%d", &second);
    printf("Great. The inputted numbers are: %d, %d.\nNow let's swap them.", first, second);
    swapInt(&first, &second);
    printf("\nResult -> %d, %d\nNow with doubles.\nPlease input 2 doubles. First: ", first, second);
    double firstD = 0, secondD = 0;
    scanf("%lg", &firstD);
    printf("Second: ");
    scanf("%lg", &secondD);
    swapDouble(&firstD, &secondD);
    printf("Result -> %.2f, %.2f\n", firstD, secondD);
}
