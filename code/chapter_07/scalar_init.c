#include <stdio.h>

int main() {
//// ANCHOR: main
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
const int c_zero = {};
#else
const int c_zero = 0;
#endif

int one = 1;
const int c_one = {1};
int three = {1 + 2};
const int c_three = 1 + 2;
//// ANCHOR_END: main

    printf("zero: %d\n", c_zero);
    printf("one: %d, %d\n", one, c_one);
    printf("three: %d, %d\n", three, c_three);
    return 0;
}
