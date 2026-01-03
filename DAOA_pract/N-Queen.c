#include<stdio.h>
#include<stdlib.h>

int x[10],n;

int place(int k,int i)
{
    for(int j=1;j<k;j++)
    {
        if(x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return 0;
        }
    }
    return 1;
}

void nqueen(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k] = i;
            if(k == n)
            {
                for(int r=1;r<=n;r++)
                {
                    for(int c=1;c<=n;c++)
                    {
                        if(x[c] == r)
                        {
                            printf("1 ");
                        }
                        else
                        {
                            printf("0 ");
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else
            {
                nqueen(k + 1);
            }
        }
    }
}


int main()
{
    printf("Enter the n number :");
    scanf("%d",&n);
    nqueen(1);
}

/*

Input: 
Enter the number of queens: 4

Output:
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0

*/
