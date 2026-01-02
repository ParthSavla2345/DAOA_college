#include <stdio.h>

void merge(int a[], int l, int m,int h)
{
    int i = l;
    int j = m + 1;
    int k = 0;
    int temp[h - l + 1];
    
    while(i <= m && j <= h)
    {
        if(a[i] < a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    
    while(i <= m)
    {
        temp[k++] = a[i++];
    }
    
    while(j <= h)
    {
        temp[k++] = a[j++];
    }
    
    for(int i = l, k =0; i<=h; i++, k++)
    {
        a[i] = temp[k];
    }
}


void mergesort(int a[],int low,int high)
{
    int m;
    if(low < high)
    {
        m = (low + high)/2;
        mergesort(a,low,m);
        mergesort(a,m+1,high);
        merge(a,low,m,high);
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
    mergesort(a,0,n-1);
    printf("\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }
}
