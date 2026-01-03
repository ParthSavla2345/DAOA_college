#include<stdio.h>
#define INF 999

int main()
{
    int a[10][10],n;
    
    printf("Enter the n nodes : ");
    scanf("%d",&n);
    
    printf("Enter the distances : ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        } 
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

/*

Input:
4
0 5 999 10
999 0 3 999
999 999 0 1
999 999 999 0

Output:
0 5 8 9
999 0 3 4
999 999 0 1
999 999 999 0

*/
