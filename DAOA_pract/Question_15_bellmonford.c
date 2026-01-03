#include<stdio.h>
int INF = 999;


int main()
{
	int n,cost[10][10], dist[10];
	int i,j,k,src;

	printf("Enter the n number : ");
	scanf("%d",&n);

	printf("Enter the costs: ");
	for(i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}

	printf("Enter the source : ");
	scanf("%d",&src);

	for(i=0; i<n; i++)
	{
		dist[i] = INF;
	}

	dist[src] = 0;

	for(k = 1; k<= n-1; k++)
	{
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
			    if( cost[i][j] != INF && dist[i] != INF && dist[i] + cost[i][j] < dist[j])
			    {
			        dist[j] = dist[i] + cost[i][j];
			    }
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
		    if( cost[i][j] != INF && dist[i] != INF && dist[j] > dist[i] + cost[i][j])
		    {
		        printf("Graph contains negative cycle!!\n");
		        return 0;
		    }
		}
	    
	}
	printf("Shortest distance from sources are : %d\n",src);
	for(i=0;i<n;i++)
	{
	    printf("Node %d : %d\n",i + 1,dist[i]);
	}
	
}

/*

Input:
Enter the number of nodes: 4
Enter the cost adjacency matrix:
0   4   5   INF
INF 0  -2   6
INF INF  0   3
INF INF INF  0
Enter the source node: 0

Output:
Shortest distances from source 0:
Node 0 : 0
Node 1 : 4
Node 2 : 2
Node 3 : 5

*/
