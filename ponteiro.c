#include <stdio.h>

void calcula(int* c) {
    printf("Calcula %d %d\n", (*c), c);
    (*c)++;
    printf("Calcuala %d %d\n", (*c), c);

}

int main() {
    int c = 10;

    printf("main %d\n", &c);

    calcula(&c);
    printf("main %d\n", &c);
} 