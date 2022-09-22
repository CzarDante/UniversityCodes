#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

void par(int start,int end);
void impar(int start,int end);
void primos(int start,int end);
int primo(int x);

int main()
{
    int i,nthreads;
    omp_set_num_threads(3);
    #pragma omp parallel
    {
        int id;
        id = omp_get_thread_num();
        printf("Thread : %d\n",id);
        #pragma omp sections
        {
            #pragma omp section
            {
                par(1,10);
                printf("Section 1 pela thread: %d\n",id);
            }
            #pragma omp section
            {
                impar(1,10);
                printf("Section 2 pela thread: %d\n",id);
            }
            #pragma omp section
            {
                primos(1,10);
                printf("Section 2 pela thread: %d\n",id);
            }
        }
    }
    return 0;
}

void par(int start,int end)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if(i%2==0)
        {
            printf("Par: %d\n",i);
        }
    }
}

void impar(int start,int end)
{
    int i;
    for (i = start; i <= end; i++)
    {
        if(i%2!=0)
        {
            printf("Impar: %d\n",i);
        }
    }
}

void primos(int start,int end)
{
    int i;
    for (i = start; i <=end; i++)
    {
        if (primo(i))
        {
            printf("Primo: %d\n",i);
        } 
    }
}

int primo(int x)
{
    if (x==1)
    {
        return 0;
    }
    int div=2;
    for (div = 2; div < x; div++)
    {
        if(x%div==0)
        {
            return 0;
        }
    }
    return 1;
    
    
}