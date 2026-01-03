#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int dfs(char board[10][10],char word[10],int i,int j,int k,int r,int c)
{
    if(k == strlen(word))
    {
        return 1;
    }
    
    if( i<0 || j<0 || i>=r || j>=c || board[i][j] != word[k])
    {
        return 0;
    }
    
    char temp = board[i][j];
    board[i][j] = '*';
    
    int found = dfs(board,word,i + 1,j,k + 1,r,c) ||
    dfs(board,word,i - 1,j,k + 1,r,c) ||
    dfs(board,word,i,j + 1,k + 1,r,c) ||
    dfs(board,word,i,j - 1,k + 1,r,c);
    
    board[i][j] = temp;
    return found;
}


int main()
{
    char board[10][10], word[10];
    int row,col,i,j;
    printf("Enter the row :");
    scanf("%d",&row);
    printf("Enter the col :");
    scanf("%d",&col);
    
    int found = 0;
    printf("Enter the grid character : ");
    for(i=0;i<row && !found;i++)
    {
        for(j=0;j<col && !found;j++)
        {
            scanf(" %c",&board[i][j]);
        }
    }
    
    printf("Enter the word : ");
    scanf("%s",word);
    
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(dfs(board,word,i,j,0,row,col))
            {
                found = 1;
            }
        }
    }
    
    if(found)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}

/*
Input:
Enter number of rows: 3
Enter number of columns: 4
Enter the grid characters:
A B C E
S F C S
A D E E
Enter word to search: ABCCED

Output:
True

*/
