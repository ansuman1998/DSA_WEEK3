#include <stdio.h>
#include <stdlib.h>
int mergesort(int *a, int low, int high, int* temp)
{   int count=0;
    if(high>low)
    {
        int mid=(high+low)/2;
        count=mergesort(a,low,mid,temp);
        count+=mergesort(a,mid+1,high,temp);

        count+=merge(a,low,mid,high,temp);
    }

    return count;
}
int merge(int *a, int low, int mid, int high, int* temp)
{
    int i=low,j=mid+1,k=low,count=0;
    while(i<=mid && j<=high)
        if(a[i]<=a[j])
            temp[k++]=a[i++];
        else
            {
            temp[k++]=a[j++];
            count+=(mid-i+1);
            }

    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=high)
        temp[k++]=a[j++];

    for(i=low;i<=high;i++){
        a[i]=temp[i];
        }

    return count;


}
int main()
{
    int n,i;
    scanf("%d",&n);
    int *a =(int *)malloc(n*sizeof(int));
    int *temp=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",mergesort(a,0,n-1,temp));
    return;
}
