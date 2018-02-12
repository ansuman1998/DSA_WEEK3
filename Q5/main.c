#include <stdio.h>
#include <stdlib.h>
void mergesort(long long int *a, long long int low, long long int high, long long int temp)
{
    if(high>low)
    {
        long long int mid=(high+low)/2;
        mergesort(a,low,mid,temp);
        mergesort(a,mid+1,high,temp);

        merge(a,low,mid,high,temp);
    }

    return;
}
void merge(long long int *a, long long int low,long long int mid, long long int high, long long int* temp)
{
    long long int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high)
        if(a[i]<=a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];

    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=high)
        temp[k++]=a[j++];

    for(i=low;i<=high;i++){
        a[i]=temp[i];}


}
long long int main()
{
    long long int n,m,l,h,i,total=0,k=0,j;
    scanf("%lld %lld", &n, &m);

    long long int *lower=(long long int *)malloc(n*sizeof(long long int));
    long long int *higher=(long long int *)malloc(n*sizeof(long long int));

    for(i=0;i<n;i++)
        scanf("%lld", &lower[i]);

     for(i=0;i<n;i++)
        {
            scanf("%lld", &higher[i]);
            total+=higher[i]-lower[i]+1;
        }

    printf("%lld\n", total);
    long long int *a=(long long int *)malloc(total*sizeof(long long int));
    long long int *temp=(long long int *)malloc(total*sizeof(long long int));


    for(i=0;i<n;i++)
        for(j=lower[i];j<=higher[i];j++)
            a[k++]=j;

    for(i=0;i<total;i++)
        printf("%lld ",a[i]);
    printf("\n");

    mergesort(a,0,total-1,temp);

    for(i=0;i<total;i++)
        printf("%lld ",a[i]);
      printf("\n");

    printf("%lld", a[m]);





}
