#include <stdio.h>

void inputName(char* name) {
    printf("What is your name? ");
    scanf("%s", name);
}

void returnName(char* name) {
    printf("What is your return name? ");
    scanf("%s", name);
}

int main() {
    char name[100];
    inputName(name);
    printf("Hello %s\n", name);
    returnName(name);
    printf("return Hello %s\n", name);
}