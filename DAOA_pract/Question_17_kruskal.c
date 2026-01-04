#include<stdio.h>
#define INF 999

int parent[10];

int find(int i)
{
    while(parent[i])
    {
        i = parent[i];
    }
    return i;
}

int uni(int a,int b)
{
    if(a != b)
    {
        parent[b] = a;
        return 1;
    }
    return 0;
}

int main()
{
    int n,cost[10][10];
    int min,a,b,u,v;
    int edges = 0;
    int mincost = 0;
    
    printf("Enter the n number : ");
    scanf("%d",&n);
    
    printf("Enter the cost : ");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    
    while(edges < n - 1)
    {
        min = INF;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        
        u = find(u);
        v = find(v);
        
        if(uni(u,v))
        {
            mincost += min;
            edges++;
        }
        cost[a][b] = cost[b][a] = INF;
    }
    
    printf("Minimum cost for spanning tree is : %d",mincost);
}

/*

Input:
Enter number of vertices: 4
Enter cost adjacency matrix:
0 10 6 5
10 0 999 15
6 999 0 4
5 15 4 0

Output:
Minimum cost of spanning tree = 19


*/
