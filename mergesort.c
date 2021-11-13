#include <stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
  
    
    int L[n1], R[n2];
  
   
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
  
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
     {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        
    
            #pragma omp parallel 
            {
                mergesort(a,l,mid);
            
                
                mergesort(a,mid+1,r);

            } 
                
        merge(a,l,mid,r);
    }
}



int main()
{
    
    int n;
    printf("enter size");
    scanf(" %d",&n);
    int a[n];


    for(int i=0 ;i<n;i++)
    {
        a[i]=rand()%1000;
        //printf("%d,",a[i]);
    }

    int l=0;
    int r=n-1;

    clock_t t; 
    t = clock();
     mergesort(a,l,r);
    t =t- clock();
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("time taken parallel %f \n",time_taken);

   

}