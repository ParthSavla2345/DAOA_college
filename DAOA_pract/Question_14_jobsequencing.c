#include<stdio.h>


int main()
{
    int n,profit[10],deadline[10], maxProfit = 0, slot[10] ={0}, job[10];
    
    printf("Enter the number of jobs : ");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        job[i] = i + 1;
        printf("Enter the deadline and profit : ");
        scanf("%d %d",&deadline[i],&profit[i]);
        slot[i] = -1;
    }
    
    // Sort the profit in descending order
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(profit[i] < profit[j])
            {
                int temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
                
                temp = deadline[i];
                deadline[i] = deadline[j];
                deadline[j] = temp;
                
                temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }
    
    // Schedule job
    
    for(int i=0;i<n;i++)
    {
        for(int j=deadline[i]-1;j>=0;j--)
        {
            if(slot[j]==-1)
            {
                slot[j] = job[i];
                maxProfit += profit[i];
                break;
            }
        }
    }
    printf("\nScheduled Jobs:\n");
    printf("Time Slot\tJob ID\n");
    for(int i=0;i<n;i++)
    {
        if(slot[i] != -1)
        {
            printf("%d\t\tJob %d\n", i + 1, slot[i]);
        }
    }
    
    printf("Maximum profit is : %d",maxProfit);
}


/*

Input :
Enter number of jobs: 4
Enter deadline and profit for each job:
Job 1 (Deadline Profit): 4 20
Job 2 (Deadline Profit): 1 10
Job 3 (Deadline Profit): 1 40
Job 4 (Deadline Profit): 1 30


Output:
Scheduled Jobs:
Time Slot      Job ID
1              Job 3
4              Job 1

Maximum Profit = 60


*/
