#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
static long num_steps = 100000;
double step;
#define NUM_THEADS 2
void main()
{
    int nthreads, i;
    double pi, sum;
    step = 1.0/(double)num_steps;
    omp_set_num_threads(NUM_THEADS);
    double t1,t2;
    t1 = omp_get_wtime();
    #pragma omp parallel
    {
        int i,id,nthrds;
        double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if (id==0){nthreads=nthrds;}
        for (i = id, sum=0.0; i < num_steps; i+=nthrds)
        {
            x=(i+0.5)*step;
            #pragma omp critical
                pi+=4.0/(1.0+x*x);
        }
    }
    pi *= step;
    t2 = omp_get_wtime();
    printf("Tempo: %lf\n",t2-t1);
    printf("pi = %lf",pi);
    
}