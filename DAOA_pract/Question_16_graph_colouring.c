#include<stdio.h>

int m,n,graph[10][10],color[10];

int issafe(int v,int c)
{
    for(int i=0;i<n;i++)
    {
        if(graph[v][i] == 1 && color[i] == c)
        {
           return 0; 
        }
    }
    return 1;
}

void graphcolour(int v)
{
    if(v == n)
    {
        printf("Color assignment : ");
        for(int i=0;i<n;i++)
        {
            printf("%d ",color[i]);
        }
        printf("\n");
        return;
    }
    
    for(int c=1;c<=m;c++)
    {
        if(issafe(v,c))
        {
            color[v] = c;
            graphcolour(v+1);
            color[v] = 0;
        }
    }
}

int main()
{
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    
    printf("Enter the number of colors:");
    scanf("%d",&m);
    
    printf("Enter the adjacency matrix :");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    printf("Possible colours are : \n");
    graphcolour(0);
}

/* 

Input:
Enter number of vertices: 4
Enter number of colors: 3
Enter adjacency matrix:
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0

Output:
Possible colorings are:
Color assignment: 1 2 3 2
Color assignment: 1 3 2 3
Color assignment: 2 1 3 1
Color assignment: 2 3 1 3
Color assignment: 3 1 2 1
Color assignment: 3 2 1 2


*/
