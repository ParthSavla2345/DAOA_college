#include<stdio.h>
#include<stdlib.h>


int main()
{
    int a[10],n,min=999,sum=0;
    
    printf("Enter the n number : ");
    scanf("%d",&n);
    
    printf("Enter the number :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    
    int s = 0;
    for(int i=0;i<n - 1;i++)
    {
        s += a[i];
        int diff = abs(sum - 2 * s);
        
        if(diff < min)
        {
            min = diff;
        }
    }
    
    printf("Minimum difference is %d",min);
    return 0;
}

/*

Input:
Enter the n number: 5
Enter the number:
3 1 2 4 3

Output:
Minimum difference is 1


*/
