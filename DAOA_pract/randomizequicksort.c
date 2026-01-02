#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int l, int r) {
    int p = l + rand()%(r-l+1);
    int t=a[p]; a[p]=a[r]; a[r]=t;
    int pivot=a[r], i=l-1;
    for(int j=l;j<r;j++)
        if(a[j]<pivot){
            i++; t=a[i]; a[i]=a[j]; a[j]=t;
        }
    t=a[i+1]; a[i+1]=a[r]; a[r]=t;
    return i+1;
}

void quickSort(int a[], int l, int r) {
    if(l<r){
        int pi=partition(a,l,r);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,r);
    }
}

int main() {
    int n,a[50];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}
