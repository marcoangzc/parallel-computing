#include "stdio.h"
#include "omp.h"
#define NUM_THREADS 16

static long num_steps = 100000;
double step;

int main()
{
    omp_set_num_threads(16);
    int i; double x, pi, sum = 0.0;
    double partial_sums[NUM_THREADS] = { 0.0 };

    step = 1.0 / (double)num_steps;

    double startTime = omp_get_wtime();
#pragma omp parallel private(i)
 {
        int id = omp_get_thread_num();

        for (i = id; i < num_steps; i+=NUM_THREADS) 
        {
            x = (i + 0.5) * step;
            partial_sums[id] = partial_sums[id] + 4.0 / (1.0 + x * x);
        }
    
 }

 for (i = 0;i < NUM_THREADS;i++) {
     sum += partial_sums[i];

 }

    pi = step * sum;

    double endTime = omp_get_wtime();
    double duration = endTime - startTime;
    
    printf("the value of pie is %f\n", pi);
    printf("the processign time is %f", duration);
    return 0;
}