#include <stdio.h>
#include <stdlib.h>

int inputThrows() {
    int throws;
    printf("How many throws do you want to consider? ");
    scanf("%d", &throws);
    return throws;
}

int main() {
    const int DICE_OPTIONS = 6;
    int throws[] = {0,0,0,0,0,0};
    int inputedThrows = inputThrows();
    int throw = 0;
    for(int i=0;i<inputedThrows;i++) {
        throw = rand()%DICE_OPTIONS;
        throws[throw]++;
    }
    for(int i=0;i<DICE_OPTIONS;i++) {
        printf("Probability for %d -> %.2f\n", i+1, (double)throws[i]/inputedThrows*100);
    }
}