#include <stdio.h>

int partition(int a[],int low,int high)
{
    int pivot = a[high], i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[i+1];
    a[i+1] = a[high];
    a[high] = t;
    return i+1;
}

void quicksort(int a[],int low,int high)
{
    if(low < high)
    {
        int m = partition(a,low,high);
        quicksort(a,low,m-1);
        quicksort(a,m+1,high);
    }
}


int main()
{
    int n,a[50];
    printf("Enter the n number : ");
    scanf("%d",&n);
    printf("Enter the array: ");
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}
