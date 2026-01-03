#include<stdio.h>

int main()
{
    int n,i,j;
    float w[20], p[20], ratio[20], m;
    printf("Enter the n number: ");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        printf("Enter weight and profit : ");
        scanf("%f %f",&w[i],&p[i]);
        ratio[i] = p[i] / w[i];
    }
    printf("Enter the weight limit : ");
    scanf("%f",&m);
    
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i] < ratio[j])
            {
                float t = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = t;
                
                
                t = w[i];
                w[i] = w[j];
                w[j] = t;
                
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    
    float profit = 0;
    
    for(i=0;i<n && m > 0;i++)
    {
        if(w[i] <= m)
        {
            profit += p[i];
            m -= w[i];
        }
        else
        {
            profit += ratio[i] * m;
            m = 0;
        }
    }
    printf("Total profit is %.2f !",profit);
}
