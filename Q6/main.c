#include <stdio.h>
#include <stdlib.h>
void mergesort(long int *a, long int low, long int high, long int temp)
{
    if(high>low)
    {
        long int mid=(high+low)/2;
        mergesort(a,low,mid,temp);
        mergesort(a,mid+1,high,temp);

        merge(a,low,mid,high,temp);
    }

    return;
}
void merge(long int *a, long int low,long int mid, long int high, long int* temp)
{
    long int i=low,j=mid+1,k=low;
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////
long int notpresent(long int*a, long int n, long int x)
{
    long int i,count=0;
    for(i=0;i<n;i++)
        if(a[i]==x)
    {
        count++;
        break;
    }

    return !count;

}
long int main()
{
    long int n,m,count,total=0;
    scanf("%ld %ld", &n, &m);
    long int *big=(long int *)malloc(n*sizeof(long int));
    long int *key=(long int *)malloc(m*sizeof(long int));
    long int *temp=(long int *)malloc(n*sizeof(long int));
    long int *ttemp=(long int *)malloc(n*sizeof(long int));

    long int i,j,k=0,l=n-1;

    for(i=0;i<n;i++)
        scanf("%ld",&big[i]);
    for(i=0;i<m;i++)
        scanf("%ld",&key[i]);

    for(i=0;i<m;i++)
    {   count=0;
        for(j=0;j<n;j++)
            if(key[i]==big[j])
            count++;
       // printf("%ld\n",count);
        total+=count;
        while(count!=0)
            {temp[k++]=key[i];
            count--;
            }
    }

    for(i=0;i<n;i++)
    {
        if(notpresent(key,m,big[i]))
           temp[k++]=big[i];
    }

    for(i=0;i<n;i++)
        printf("%ld ", temp[i]);
    printf("\n");
    printf("%ld\n", total);


    mergesort(temp,total,n-1,ttemp);

    for(i=0;i<n;i++)
        printf("%ld ", temp[i]);
    printf("\n");

}
