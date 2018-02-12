#include <stdio.h>
#include <stdlib.h>
int n;
void print(int *a, int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
}
void quicksort(int *a, int low, int high)
{
    if(low>=high)
        return;

    int pi= partition(a,low,high);
    printf("low %d pi %d high %d\n",low,pi,high);
    quicksort(a,low,pi-1);
    quicksort(a,pi+1,high);
    return;

}
int partition(int *a, int low, int high)
{
    int i=low-1,j,temp;
    int pivot=a[high];
    for(j=low;j<high;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    print(a,n);
    return i+1;

}
int main()
{
    int i;
    scanf("%d", &n);
    int *a = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    print(a,n);
    quicksort(a,0,n-1);
    print(a,n);
}
