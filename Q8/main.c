#include <stdio.h>
#include <stdlib.h>
merge_sort(int *a, int *temp, int low, int high)
{
    if(low>=high)
        return; ////TERMINATING CONDITION OF RECURSION
    else
    {
        int mid=(low+high)>>1;
        merge_sort(a,temp,low,mid);
        merge_sort(a,temp,mid+1,high);

        /////////MERGE SECTION OF THE MERGE SORT////////////
        int i,j,k;
        i=low;
        k=low;
        j=mid+1;

        while(i<=mid && j<=high)
            if(a[i]<=a[j])
                temp[k++]=a[i++];
            else
                temp[k++]=a[j++];

        while(i<=mid)
            temp[k++]=a[i++];
        while(j<=high)
            temp[k++]=a[j++];

        for(i=low;i<=high;i++)
            a[i]=temp[i];
        ////////////////////////////////////////////////////////
    }
}
////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
int main()
{
    int m,n,i=0,median,ttemp;
    scanf("%d %d", &m, &n);
    int *a = (int *)malloc(n*sizeof(int));
    int *temp= (int *)malloc(n*sizeof(int));
    int *result = (int *)malloc(n*sizeof(int));

    while(i<n)
        scanf("%d", &a[i++]);

    for(i=0;i<m;i++)
        result[i]=-1;

    merge_sort(a,temp,0,m-1);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    for(i=m;i<n;i++)
    {
        if(i%2==0)
        {
            median=(a[i/2]+a[(i+1)/2])/2;
            if(a[i]>3*median)
                result[i]=1;
            else
                result[i]=0;
        }
        else
        {
            median=a[i/2];
            if(a[i]>3*median)
                result[i]=1;
            else
                result[i]=0;
        }

        int j=i-1,k;
        ttemp=a[i];
        while(a[j]>ttemp&&j>-1)
            {
                a[j+1]=a[j];
                j--;
            }
        j++;
    printf("The selected element %d will shift to %d\n",i, j);
        a[j]=ttemp;
    for(k=0;k<n;k++)
        printf("%d ",a[k]);
        printf("\n");
    }

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",result[i]);
}
