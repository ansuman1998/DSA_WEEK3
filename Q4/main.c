#include <stdio.h>
#include <stdlib.h>
#include <math.h>

////////////////////////GLOBAL VARIABLES FOR EASE OF ACCESS/////////////////////
int **teams, *teamweight, *weight, answer=0;
int top=0;
//////////////////////////////UTILITARIAN FUNCTIONS/////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void print(int *a, int m)
{
    int i;
    for(i=0;i<m;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int fact(int n)
{
    int prod=1;
    while(n!=0)
    {
        prod*=n;
        n--;
    }
    return prod;
}
///////////////////////////////////////////////////////////////////////////////////
///////////////////////////TEAM FORMING FUCTION////////////////////////////////////
void choose(int *a, int n, int m, int index, int i)
{
    if(index==m)
    {
        int j;
        for(j=0;j<m;j++)
            {
                teams[top][j]=a[j];
                teamweight[top]+=weight[a[j]];
            }
        top++;
    }

    int j;
    for(j=i+1;j<n;j++)
        {
            a[index]=j;
            choose(a,n,m,index+1,j);
        }
}
///////////////////////////////////////////////////////////////////////////////////
/////////////////////////WEIGHT UPDATING FUNCTION//////////////////////////////////
void update_weight(int team_num, int m)
{
    int i,j;
    for(i=0;i<team_num;i++)
        teamweight[i]=0;
    for(i=0;i<team_num;i++)
        for(j=0;j<m;j++)
        teamweight[i]+=weight[teams[i][j]];
}
/////////////////////////////////////////////////////////////////////////////////
//////////////////////TEAM COUNT FUNCTION////////////////////////////////////////
void countteam(int team_num, int m)
{
    int max=0,maxi=0,i=0,j;
    for(i=0;i<team_num;i++)
    {
        if(teamweight[i]>max)
        {
            max=teamweight[i];
            maxi=i;
        }
    }
    print(teams[maxi],m);
    answer++;
    for(j=0;j<m;j++)
        weight[teams[maxi][j]]--;
    update_weight(team_num, m);

}
////////////////////////////////////////////////////////////////////////////////////
int allweights(int *weights, int n)
{
    int i,flag=0;
    for(i=0;i<n;i++)
        if(weight[i]==0)
            flag++;
    return n-flag;
}

///////////////////////////////DRIVER FUNCTION/////////////////////////////////////
int main()
{
    int n,m,i;
    scanf("%d %d", &n, &m);
    weight = (int *)malloc(n*sizeof(int));
    int *temp= (int *)malloc(m*sizeof(int)); //Just a temporary space to hold states while team creation
    for(i=0;i<n;i++)
        scanf("%d",&weight[i]);
  ///////////////////TEAM RELATED PARAMETER CALCLULATION///////////////////////////////////
    int team_num= fact(n)/(fact(m)*fact(n-m));
    printf("%d\n", team_num);
    teams= (int **)malloc(team_num*sizeof(int *));
    teamweight=(int *)malloc(team_num*sizeof(int));
    for(i=0;i<team_num;i++)
    {
        teams[i]=(int *)malloc(m*sizeof(int));
        teamweight[i]=0;
    }
    ////////////////////////////////////////////////////
    choose(temp,n,m,0,-1);
    for(i=0;i<team_num;i++)
    {
        print(teams[i],m);
        printf("%d\n",teamweight[i]);

    }
    /////////////////////////////////////////////////////
    while(allweights(weight,n)>=m)
    {
        countteam(team_num,m);
    }
    printf("%d\n", answer);
    return 0;
}
