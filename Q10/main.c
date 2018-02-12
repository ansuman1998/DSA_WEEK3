#include <stdio.h>
#include <stdlib.h>
int bubble_sort(int *a, int n)
{
    int i,j,temp,count=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                count++;

            }
        }
    }
}
int select_sort(int *a, int n)
{
    int i, mini, min, temp, count=0,j;
    for(i=0;i<n;i++)
    {
        mini=i;
        min=a[i];
        for(j=i+1;j<n;j++)
            if(a[j]< min)
        {
            min=a[j];
            mini=j;
        }

        if(mini!=i)
        {
            temp=a[i];
            a[i]=a[mini];
            a[mini]=temp;
            count++;

        }

    }

    return count;
}

int insert_sort(int *a, int n)
{
    int i,j,temp,ttemp,count=0;
    for(i=1;i<n;i++)
    {
        j=i-1;
        temp=a[i];
        while(a[j]>temp&&j>-1)
        {
           ttemp=a[j+1];
           a[j+1]=a[j];
           a[j]=ttemp;
           j--;
           count++;
        }



    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    int *b=(int *)malloc(n*sizeof(int));
    int *in=(int *)malloc(n*sizeof(int));
    int *s=(int *)malloc(n*sizeof(int));

    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
            b[i]=a[i];
            in[i]=a[i];
            s[i]=a[i];
        }
        printf("\n");

    //countbubble=bubble_sort(a,n);
    //countselect=select_sort(a,n);

    printf("%d\n",bubble_sort(b,n));
    printf("%d\n",select_sort(s,n));
    printf("%d\n",insert_sort(in,n));

      for(i=0;i<n;i++)
        printf("%d ",s[i]);
        printf("\n");
}
