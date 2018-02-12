#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *a,sum=0,min=INT_MAX, n, m,temp=0;
int check(int x)
{
    int c=0,i=0,temp=0;
    while(i<m)
    {

        if(a[i]>x)
            return 0;
        if(temp+a[i]>x)
            {   printf("%d ",temp);
                temp=a[i++];
                c++;
            }
        else
            temp+=a[i++];
    }
    c++;
    printf("%d ", temp);
    printf("\n");
    printf("No of people needed %d\n",c);
    if(c<=n)
        return 1;


}
int main()
{
    int i;
    a = (int *)malloc(m*sizeof(int));
   scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
        {
            scanf("%d", &a[i]);
            if(a[i]<min)
                min=a[i];
            sum+=a[i];
        }

    //printf("%d %d\n",min,sum);
    /* Here the monotonic function is on the possible answer. We need to place the partitions(=friends -1, cows) on the shelves
    (difference in positions on the barn) so that the maximum gap between the partitions is minimum. So if we choose two values
    x,y with y<x and we notice that if f(x) = FALSE, there is no way that f(y) will be TRUE so f(y) is false. So we set a value
    which is definitely TRUE and */

    /*Sum stores the sum of values, i.e. the total number of books. In the worst case scenario, there is a single friend, and this sum
    is the minimum possible solution. So the upper limit in all cases other than the worst case is less than sum. f(sum) is T. */

    /*In the best case scenario, number of friends is equal to number of shelves, or at least that's what is implied. Which means the minimum
    shelf would be the answer there. In cases, other than best cases answer > min. So f(min-1) is F. */

    int high=sum;
    int low=min;
    int mid;

    while(low<high)
    {
        mid=(low+high)>>1;
        printf("Present low %d, mid %d, high is %d\n",low,mid,high);
        if(check(mid)==1)
            {
                high=mid;
                printf("High updated\n");
            } //Since we don't have a separate if statement to check mid, and we shouldn't. SO high includes the case of mid, for if mid-1 isn't successful, mid will be missed.
        else
            {
                low=mid+1;
            }
                printf("Low updated\n");

    }

    printf("%d\n",high);






}
