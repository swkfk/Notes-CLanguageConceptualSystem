#include <stdio.h>

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 202311L
#define alignof _Alignof
#endif

#if !defined(__GNUC__) && (!defined(__STDC_VERSION__) || __STDC_VERSION__ < 202311L)
#error "Do not support typeof(...)"
#endif

int main() {

//// ANCHOR: main
// Error: clang(sizeof_alignof_incomplete_or_sizeless_type)
// printf("int[]:\t\t%zd\t%zd\n", sizeof(int[]), alignof(int[]));

printf("int[5]:\t\t%zd\t%zd\n", sizeof(int[5]), alignof(int[5]));
printf("int[2+3]:\t%zd\t%zd\n", sizeof(int[2 + 3]), alignof(int[2 + 3]));

const int N = 10;
// int[N] 是一个变长数组类型！
printf("int[N]:\t\t%zd\t%zd\n", sizeof(int[N]), alignof(int[N]));
//// ANCHOR_END: main

//// ANCHOR: int_t_t
printf("int[5][10]:\t\t%zd\t%zd\n", sizeof(int[5][10]), alignof(int[5][10]));
typedef typeof(int[5]) INT_5_10[10];
printf("typeof(int[5])[10]:\t%zd\t%zd\n", sizeof(INT_5_10), alignof(INT_5_10));
//// ANCHOR_END: int_t_t

    return 0;
}