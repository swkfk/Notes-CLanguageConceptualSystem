#include <stdio.h>

void put_array(const char *name, int a[][3]) {
    printf("%s[2][3]:\n", name);
    for (int i = 0; i < 2; i++) {
        printf("\t");
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
//// ANCHOR: main
int a1[2][3] = {{1, 2, 3}, {4, 5, 6}};
int a2[2][3] = {{1, 2, 3}};
int a3[2][3] = {{1, 2}, {3, 4, 5}};
// 因为内存是一维的，最后都是标量对象（及限定类型）依次排列开
int a4[2][3] = {1, 2, 3, 4};
//// ANCHOR_END: main

    put_array("a1", a1);
    put_array("a2", a2);
    put_array("a3", a3);
    put_array("a4", a4);
    return 0;
}
