
#include <stdio.h>
#define v 100

int j=0;
void dfs(int a_matrix[v][v],int n,int visited[],int start,int res[])
{


        visited[start]=1;
        for(int i=0;i<n;i++)
        {
            if(a_matrix[start][i]==1&& visited[i]==0 )
            {
                dfs(a_matrix,n,visited,i,res);
            }
        }

    res[j++]=start;


}
void toposort(int a_matrix,int n)
{
    int visited[v]={0};
    int res[v];
    j=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            dfs(a_matrix,n,visited,i,res);
        }
    }
    printf("the topological sort:");
    for(int i=n-1;i>=0;i--)
    {
        printf("%d",res[i]);
    }


}

int main()
{
    int a_matrix[v][v];
    int n;

    printf("enter the no of vertices:");
    scanf("%d",&n);
    printf("enter the adjaceny matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a_matrix[i][j]);
        }
    }


    toposort(a_matrix,n);
    return 0;
}

