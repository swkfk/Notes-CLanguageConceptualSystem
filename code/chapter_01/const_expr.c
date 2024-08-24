#include <stdio.h>

int main() {

//// ANCHOR: main
int x[5][(int) (10.0)];
int y[5][(int) (+10.0)];
int i = 0, j = 0;

sizeof(x[i++]);
printf("i: %d\n", i);

sizeof(y[j++]);
printf("j: %d\n", j);
//// ANCHOR_END: main

    return 0;
}
