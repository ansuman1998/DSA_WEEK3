#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   int n, min_length=100, max_length=0;
    char a[100][100];
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
        scanf("%s",a[i]);
    for(i=0;i<n;i++)
    {
        if(strlen(a[i])<min_length)
            min_length=strlen(a[i]);
        if(strlen(a[i])>max_length)
            max_length=strlen(a[i]);
    }
    for(i=0;i<n;i++)
    {
        int min_index=i;
        char min[100], temp[100];
        strcpy(min,a[i]);
        for(j=i+1;j<n;j++)
        {
            if(strcmp(a[j],min)==-1)
            {
                strcpy(min,a[j]);
                min_index=j;
            }
        }

        strcpy(temp,a[i]);
        strcpy(a[i],a[min_index]);
        strcpy(a[min_index],temp);
    }

    for(i=min_length;i<=max_length;i++)
    {
        for(j=0;j<n;j++)
            if(strlen(a[j])==i)
            printf("%s\n",a[j]);
    }



}
