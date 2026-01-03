#include<stdio.h>

int n,w[10],x[10],target;

void sumofsubset(int currentsum,int index,int remainingsum)
{
    if(currentsum == target)
    {
        printf("Subset: ");
        for(int i=0;i<n;i++)
        {
            if(x[i] == 1)
            {
               printf("%d ",w[i]); 
            }
        }
        printf("\n");
        return;
    }
    
    if(index >= n || currentsum > target || currentsum + remainingsum < target)
    {
        return;
    }
    
    x[index] = 1;
    sumofsubset(currentsum + w[index],index + 1, remainingsum - w[index]);
    
    x[index] = 0;
    sumofsubset(currentsum, index + 1, remainingsum - w[index]);
}


int main()
{
    int totalSum = 0;
    printf("Enter the n number : ");
    scanf("%d",&n);
    
    printf("Enter the elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        totalSum += w[i];
    }
    
    printf("Enter the target : ");
    scanf("%d",&target);
    
    printf("\nSubsets with sum %d are:\n", target);
    sumofsubset(0,0,totalSum);
}


/*

Input:
Enter number of elements: 5
Enter the elements:
5 10 12 13 15
Enter target sum: 30

Output:
Subsets with sum 30 are:
Subset: 5 10 15
Subset: 5 12 13


*/
