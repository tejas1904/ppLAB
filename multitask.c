#include<stdio.h>
#include<math.h>
#include<omp.h>

void generate_prime(int n)
{
    int a[n];
    int k=0;
    int flag=0;
    
    for(int i=2;i<n;i++)
    {   flag=0;
        for(int j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                flag++;

            }
        }
        if(flag==2)
        {
            a[k++]=i;
            
        }
        
    }

    for(int i=0;i<k;i++)
    {
        printf("%d " ,a[i]);
    }
}

void generate_sine(int n)
{
    double angles[n+1];
    double sines[n+1];
    for(int i=0;i<=n;i++)
    {
        angles[i]=(double)i/(double)n*M_PI;
        sines[i]=sin(angles[i]);
    }

    for(int i=0;i<n;i++)
    {
        printf("%f degres %f sine \n" ,angles[i],sines[i]);
    }

}

int main()

{
    int n=5;
    #pragma omp parallel sections
    {
        #pragma omp section
            generate_prime(n);
        #pragma omp section
            generate_sine(n);
    }
}