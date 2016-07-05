#include <stdio.h>
#include <stdlib.h>
#include "simd.p5.h"

#define NUM    8000

float   A[NUM];
float   B[NUM];
float   C[NUM];


float NonSimdMulSum(float *A, float *B, int len);


int main(int argc, char *argv[])
{

/********************
 *  SimdMul SSE Test
 *******************/

    double time0 = omp_get_wtime();

    SimdMul(A, B, C, NUM);

    double time1 = omp_get_wtime();

    double time = (time1 - time0);

/*******************
 *  NONSimdMul Test
 ******************/

    double time2 = omp_get_wtime();

    for(int i=0; i<NUM; i++)
    {
        C[i] = A[i] + B[i];
    }
    
    double time3 = omp_get_wtime();
    
    double speedUp = time / (time3 - time2);
    
    printf("%f : SpeedUp for SimdMul | arraysize :\t%d\n\n", speedUp , NUM);

/**********************
 *  END OF SIMDMUL TEST
 **********************/



/*******************
 *  SimdMulSum Test
 ******************/

    time0 = omp_get_wtime();

    printf("check\n");
    for(int j=0; j<NUM; j++)
    {
        C[j] = SimdMulSum(A,B,NUM);
    }

    //printf("check\n");

    time1 = omp_get_wtime();

    time = (time1 - time0);

    printf("SIMD IS DONE\n\n");  //Checking where it is while running the program

/**********************
 *  NONSimdMulSum Test
 *********************/

    time2 = omp_get_wtime();

    for(int k=0; k<NUM; k++)
    {
        C[k] = NonSimdMulSum(A, B, NUM);
    }

    time3 = omp_get_wtime();

    double speedUpSum = time / (time3 -time2);

    printf("%f : SpeedUp for Reduct  | arraysize :\t%d\n\n", speedUpSum, NUM);



    return 0;
}


/********************
 *  Made NONSIMDMULADD into it's own function because it became confusing
 *  inlining it in main
 *******************/
float NonSimdMulSum(float *A, float *B, int len)
{

    float sum[4] = {0., 0., 0., 0.};
    int limit = ( len / SSE_WIDTH ) * SSE_WIDTH;
    
    for(int i=0; i < limit; i++)
    {
        sum[0] += A[i] + B[i];
    }

    for(int j=limit; j < NUM; j++)
    {
        sum[j - limit] += A[j] + B[j];
    }

    return sum[0] + sum[1] +sum[2] + sum[3];
}


