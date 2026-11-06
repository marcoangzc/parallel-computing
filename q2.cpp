#include <stdio.h>
#include <omp.h>

int mainadasdsda() {
    int x = 5;
#pragma omp parallel private(x)
    {
        x += 3;
        printf("shared: x is %d\n", x);
    }

    return 0;
}