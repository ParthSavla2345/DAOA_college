#include<stdio.h>

int max(int a,int b)
{
    return a>b?a:b;
}


int main()
{
    int n,w[10],v[10],W;
    
    printf("Enter the n number : ");
    scanf("%d",&n);
    
    printf("Enter the weights and values : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&w[i],&v[i]);
    }
    
    printf("Enter the limit : ");
    scanf("%d",&W);
    
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if(w[i - 1] <= j)
            {
                dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]],dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    printf("Maximum profits are : %d",dp[n][W]);
}

/*

Input:
Enter number of items: 3
Enter weight and value of each item:
10 60
20 100
30 120
Enter knapsack capacity: 50

Output:
Maximum value = 220

*/
