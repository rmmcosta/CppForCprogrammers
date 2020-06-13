#include <stdio.h>

void fillSingleArr(int *xptoPtr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(xptoPtr + i) = i;
    }
}

void fillMulti(int *ptr, int size)
{
    for (int i = 0; i < size * size; i++)
    {
        *(ptr + i) = i;
    }
}

int main()
{
    const int size = 5;
    int xpto[size];
    int *xptoPtr = xpto; //equivalent to &xpto[0]
    printf("xpto: %d, xpto ptr: %d, xpto address: %d\n", xpto, xptoPtr, &xpto);
    fillSingleArr(xptoPtr, size);
    for (int i = 0; i < size; i++)
    {
        printf("address: %d\tvalue: %d\n", &xpto[i], xpto[i]);
    }
    int multi[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("address: %d\n", &multi[i][j]);
        }
    }

    fillMulti(multi, size);
    int *multiPtr = multi;
    for (int i = 0; i < size * size; i++)
    {
        printf("value: %d\n", *(multiPtr+i));
    }
    return 0;
}