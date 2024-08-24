void foo() {
    int a[10] = {1};
    0 [a] = 1;
}

int main(int argc, char *argv[]) {
    foo();
    (*foo)();
    (&foo)();
    return 0;
}
