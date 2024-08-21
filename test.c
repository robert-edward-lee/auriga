int stack_smasher(void) {
    int x[2];

    x[0] = 0;
    x[1] = 1;
    x[2] = 2;

    return x[0] + x[1];
}

int main(void) {
    int x;

    x = stack_smasher();

    return x;
}
