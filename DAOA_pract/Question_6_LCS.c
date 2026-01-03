#include<stdio.h>
#include<string.h>

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    char x[50],y[50];
    
    printf("Enter string :");
    scanf("%s",x);
    
    printf("Enter string :");
    scanf("%s",y);
    
    int m = strlen(x);
    int n = strlen(y);
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            
            else if(x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j],dp[i][j-1]);
            }
        }
    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';
    int i = m;
    int j = n;
    while(i>0 && j>0)
    {
        if(x[i - 1] == y[j - 1])
        {
            lcs[index - 1] = x[i - 1];
            i--; 
            j--;
            index--;
        }
        else if(dp[i - 1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf("LCS length : %d",dp[m][n]);
    printf("\nLCS character : %s",lcs);
}
