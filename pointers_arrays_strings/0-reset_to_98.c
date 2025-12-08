#include <stdio.h>

void reset_to_98(int *n);

int main(void)
{
    int a = 42;
    printf("Before: %d\n", a);
    reset_to_98(&a);
    printf("After: %d\n", a);
    return 0;
}

