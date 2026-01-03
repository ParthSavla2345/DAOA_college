#include<stdio.h>
#include<stdlib.h>

int magic[8][9] = {
    {8, 1, 6, 3, 5, 7, 4, 9, 2},
    {6, 1, 8, 7, 5, 3, 2, 9, 4},
    {4, 9, 2, 3, 5, 7, 8, 1, 6},
    {2, 9, 4, 7, 5, 3, 6, 1, 8},
    {8, 3, 4, 1, 5, 9, 6, 7, 2},
    {4, 3, 8, 9, 5, 1, 2, 7, 6},
    {6, 7, 2, 1, 5, 9, 8, 3, 4},
    {2, 7, 6, 9, 5, 1, 4, 3, 8}
};


int main()
{
    int s[9],mincost=999;
    printf("Give a series of number : ");
    for(int i=0;i<9;i++)
    {
        scanf("%d",&s[i]);
    }
    
    for(int i=0;i<8;i++)
    {
        int cost=0;
        for(int j=0;j<9;j++)
        {
            cost += abs(s[j] - magic[i][j]);
        }
        if(cost < mincost)
        {
            mincost = cost;
        }
    }
    printf("Minimum : %d",mincost);
}


/*

Input:
Enter the elements of the 3x3 matrix:
4 9 2
3 5 7
8 1 5

Output:
Minimum cost to convert into a magic square = 1

*/
