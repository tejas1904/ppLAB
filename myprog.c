#include<stdio.h>
#include <omp.h>
int main()
{
    if( omp_get_dynamic() )
    {
        omp_set_dynamic(0);
    }
    omp_set_num_threads(3);
    int n = 4;                 // shared
                     // shared
    int b[]={10,20,30,40,50,60};
    int i=0;
    int a = 0; 
    #pragma omp parallel for firstprivate(a)
    for (i = 0; i <6; i++) // i private
    {
          a=a+1;
          b[i]=a+b[i];      // b private
    
    }

    for(int i=0;i<6;i++)
    { printf(" %d ",b[i]);}

    printf("\n");

}