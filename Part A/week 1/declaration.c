#include <stdio.h>

int getNum() {
    return 10;
}

int main() {
    int a = 3;
    printf("%d\n",a);
    int b = 5;
    printf("%d\n",b);
    printf("%d\n",getNum());
    int c = 12;
    printf("%d\n",c);
}