#include<stdio.h>
#include<math.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int m1=2,n1=3,n2=3;
    int a[2][3];
    int b[3];
    int c[2];
    srand(time(NULL));

    printf("enter first matrix");

    for(int i=0;i<m1;i++)
    {
        for(int j=0;j<n1;j++)
        {
            a[i][j]=rand()%100;
        }
    }

    printf("enter vector");

    for(int i=0;i<n2;i++)
    {
        b[i]=rand()%100;
    }

    omp_set_num_threads(3);
    #pragma omp parallel for

    for(int row=0;row<m1;row++)

    {
        c[row]=0;
        for(int j=0;j<n2;j++)
        {
            c[row]=c[row]+(a[row][j] * b[j]);
        }


    }

    for(int i=0;i<m1;i++)
    {
        printf(" \n %d \n",c[i]);
    }




}