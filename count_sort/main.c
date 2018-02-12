#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int n;
    scanf("%d", &n);
    int *a=(int *)malloc(n*sizeof(int));
    int max=INT_MIN, i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>max)
            max=a[i];
    }
    int *count=(int *)malloc((max+1)*sizeof(int));
    for(i=0;i<=max;i++)
        count[i]=0;

    for(i=0;i<n;i++)
        count[a[i]]++;
    for(i=0;i<=max;i++)
        printf("%d ", count[i]);
    printf("\n");

    for(i=0;i<=max;i++)
        while(count[i]!=0)
        {
            printf("%d ",i);
            count[i]--;
        }

}
