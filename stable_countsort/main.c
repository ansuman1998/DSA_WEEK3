#include <stdio.h>
#include <stdlib.h>
struct node
{
    int n;
    char c;

};
struct node comb[10];
struct node sorted[10];
int top= 0;
int main()
{
    int n,a,i;
    char b;
    scanf("%d",&n);
    while(n!=0)
    {
        scanf("%d %c",&a,&b);
        comb[top].n=a;
        comb[top].c=b;
        top++;
        n--;
    }

    int count[3];
    for(i=0;i<3;i++)
        count[i]=0;
    for(i=0;i<=top;i++)
    {
        if(comb[i].c=='R')
            count[0]++;
        else if(comb[i].c=='B')
            count[1]++;
        else
            count[2]++;
    }

    for(i=1;i<3;i++)
        count[i]+=count[i-1];
    for(i=top;i>=0;i--)
    {
        if(comb[i].c=='R')
            {
                sorted[count[0]].n=comb[i].n;
                sorted[count[0]].c='R';
                count[0]--;
            }
        else if(comb[i].c=='B')
            {
                sorted[count[1]].n=comb[i].n;
                sorted[count[1]].c='B';
                count[1]--;
            }
        else
            {
                sorted[count[2]].n=comb[i].n;
                sorted[count[2]].c='G';
                count[2]--;
            }
    }

    for(i=0;i<=top;i++)
        printf("%d %c\n", sorted[i].n, sorted[i].c);

}
