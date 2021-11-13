#include <stdio.h>
#include <omp.h>

long long factorial(long n)
{
    if(n==0)
        return 1;
    
    else 
        return n*factorial(n-1);
}

void main()

{   
    int num_threads;
    long long factorials[]={10,20,30,40,50,60};

    printf("enter the number of threads\n");
    scanf("%d",&num_threads);

    if( omp_get_dynamic() )
    {
        omp_set_dynamic(0);
    }
    omp_set_num_threads(num_threads);

    printf("using %d num threads\n\n", omp_get_max_threads());

    //for(int i=0;i<=10;i++)
    //{
    //    factorials[i]=factorial(i);
    //}

    int i=0; 
    int j = 1;
    #pragma omp parallel for firstprivate(j) //making firstprivate shares value for each thread
    for(i=0; i<=5; i++ )
    {
        j = j+1;
        factorials[i] = j + factorials[i]; 
    }

        for(int i=0;i<=5;i++)
            printf("factorial(%d) =  %lld * [%d] = %lld \n",i,factorial(i),i,factorials[i]);

    
}