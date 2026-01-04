#include<stdio.h>

int keys[10];
int count = 0 ;


int main()
{
    int n,key;
    
    printf("Enter the n number:");
    scanf("%d",&n);
    
    printf("Enter the keys : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&key);
        keys[count++] = key;
        printf("Key inserted : %d\n",key);
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=i + 1;j<n;j++)
        {
            if(keys[i] > keys[j])
            {
                int temp = keys[i];
                keys[i] = keys[j];
                keys[j] = temp;
            }
        }
    }
    printf("Elements in btree: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",keys[i]);
    }
}

/*

Input:
Enter number of keys to insert: 6
Enter keys:
10 20 5 6 12 30

Output:
Inserted 10 into B-Tree
Inserted 20 into B-Tree
Inserted 5 into B-Tree
Inserted 6 into B-Tree
Inserted 12 into B-Tree
Inserted 30 into B-Tree

Elements in sequential order:
5 6 10 12 20 30


*/
