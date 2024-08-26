int main() {
    //// ANCHOR: main
int num = 10;

const int *cip = &num; // pointer to `const int`
// Error: clang(typecheck_assign_const)
// *cip = 1;
cip = &num;
// Error: clang(typecheck_assign_const)
// *cip = 1;

int *const ipc = &num; // const qualify `int *`
// Error: clang(typecheck_assign_const)
// ipc = &num;
*ipc = 11;
    //// ANCHOR_END: main

    return 0;
}
