#include <stdio.h>
#include <stdlib.h>
int n;
void print(int *a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void merge_sort(int *a, int *temp, int low, int high)
{
    if(low>=high)
        return;

    int mid=(low+high)>>1;
    merge_sort(a,temp,low,mid);
    merge_sort(a,temp,mid+1,high);

    int i=low,j=mid+1,k=low;

    while(i<=mid&&j<=high)
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=high)
        temp[k++]=a[j++];

    for(i=low;i<=high;i++)
        a[i]=temp[i];
}
void shuffle(int *a, int *temp, int low, int high)
{   if(low>=high)
        return;
    int i;
    int mid=(low+high)>>1;
    for(i=low;i<=mid;i++)
    {
        temp[i]=a[low+2*(i-low)];

    }
    for(i=mid+1;i<=high;i++)
    {
        temp[i]=a[low+1+2*(i-mid-1)];
    }

    for(i=low;i<=high;i++)
        a[i]=temp[i];

    shuffle(a,temp,low,mid);
    shuffle(a,temp,mid+1,high);
    for(i=low;i<=high;i++)
        a[i]=temp[i];
}
int main()
{
    int i;
    scanf("%d", &n);
    int *a= (int *)malloc(n*sizeof(int));
    int *temp= (int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    merge_sort(a,temp,0,n-1);
    print(a,n);
    shuffle(a,temp,0,n-1);
    print(a,n);
    print(a,n);
}
