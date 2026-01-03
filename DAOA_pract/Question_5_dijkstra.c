#include <stdio.h>
#define INF 999

int main()
{
    int n, cost[10][10], dist[10],visited[10]={0},src,i;
    printf("Enter the n nodes:");
    scanf("%d",&n);
    
    printf("Enter the costs : ");
    for(i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    
    printf("Enter the source : ");
    scanf("%d",&src);
    
    for(i=0;i<n;i++)
    {
        dist[i] = cost[src][i];
    }
    visited[src] = 1;
    
    for(int c=1;c<n;c++)
    {
        int min = INF, u;
        for(i=0;i<n;i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }
        
        visited[u] = 1;
        
        for(int v=0;v<n;v++)
        {
            if(dist[v] > dist[u] + cost[u][v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }
    
    printf("Distances : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",dist[i]);
    }
}
