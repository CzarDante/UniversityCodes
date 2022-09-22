#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

int main()
{
    int i,nthreads;
    printf("Informe a quantidade de threads: ");
    scanf("%d",&nthreads);
    omp_set_num_threads(nthreads);
    #pragma omp parallel
    {
        int id;
        id = omp_get_thread_num();
        #pragma omp single
        {
            printf("\n INICIANDO MUNDO PARALELO\n");
        }
        printf(" EU SOU A THREAD %d\n",id);
        #pragma omp barrier
        #pragma omp master
        {
            printf("FIM\n");
        }
    }

    return 0;
}