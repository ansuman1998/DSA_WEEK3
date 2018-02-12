#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,i,sum,min,j;
    scanf("%d",&t);
    while(t!=0)
    {   min=33000;
        scanf("%d",&n);
        int *height= (int *)malloc(n*sizeof(int));
        int *cost= (int *)malloc(n*sizeof(int));

        for(i=0;i<n;i++)
            scanf("%d",&height[i]);
        for(i=0;i<n;i++)
            scanf("%d",&cost[i]);
        for(i=0;i<n;i++)
        {   sum=0;
            for(j=0;j<n;j++)
            {
                sum+=abs(height[i]-height[j])*cost[j];
            }
            if(sum<min)
                min=sum;
        }

        printf("%d\n", min);
        t--;

    }
}
