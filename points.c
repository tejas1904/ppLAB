#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
#include<math.h>

int get_dist(int x1,int y1,int x2,int y2)
{
    int dist=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return dist;
}

void cluster()
{
    int k=4;
    int n=10;
    int cluster_centers[4][4]={{25,25},{75,25},{25,75},{75,75}};
    int cluster_count[]={0,0,0,0};
    int points[n][n];

    srand(time(NULL));
    for(int i=0;i<n;i++)
    {
        points[i][0]=rand()%1000;
        points[i][1]=rand()%1000;

    }

    #pragma omp parallel for

    for(int i=0;i<=n;i++)
    {
        int min_dist=1000;
        int dist=0;
        int cluster_index=0;

        for(int j=0;j<k;j++)
        {
            dist=get_dist(points[i][0],points[i][1],cluster_centers[j][0],cluster_centers[j][1]);
            if(dist<min_dist)
            {
                min_dist=dist;
                cluster_index=j;
            }
            cluster_count[cluster_index]++;
        }
    }

    for(int i=0;i<4;i++)
        printf(" %d ",cluster_count[i]);
}




int main()
{
    cluster();
    printf("\n");
}