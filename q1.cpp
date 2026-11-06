#include <stdio.h>
#include <omp.h>

int maindsdadsad() {
    //a set thread need to use
    omp_set_num_threads(40);
    //get the start time
    double startTime = omp_get_wtime();
    //create and start parallel region
#pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("Hello World from thread %d\n", tid);
    }
    //get the end time
    double endTime = omp_get_wtime();
    //calculate the duration
    double duration = endTime - startTime;
    printf("Processign time: %f", duration);
    return 0;
}