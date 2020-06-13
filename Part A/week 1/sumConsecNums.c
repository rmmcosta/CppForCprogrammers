/*  Convert this program to C++
*   change to C++ io
*   change to one line comments
*   change defines of constants to const
*   change array to vector<>
*   inline any short function
*/

#include <stdio.h>
#define N 20

void sumConsec(int *accum, int init, int nums[])
{
    *accum = init;
    for (int i = 0; i < N; i++)
    {
        *accum += nums[i];
    }
}

int main()
{
    int init = 0;
    printf("What is the initial value? ");
    scanf("%d", &init);
    int nums[N];
    int accum = 0;
    for (int i = 0; i < N; i++)
    {
        nums[i] = i;
    }
    sumConsec(&accum, init, nums);
    printf("accumulated value -> %d\n", accum);
    return 0;
}