#include<stdio.h>
#include<stdlib.h>

void topo(int a[10][10], int n);

int main()
{
    int a[10][10], n;
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix of the graph: \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    topo(a, n);
    return 0;
}

void topo(int a[10][10], int n)
{
    int indegree[10];
    int s[10], T[10];
    int top = -1;

    // Calculate indegree for each vertex
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += a[j][i];
        }
        indegree[i] = sum;
        if(indegree[i] == 0)
        {
            top++;
            s[top] = i;
        }
    }

    int idx = 0;

    while(top != -1)
    {
        int u = s[top];
        top--;
        T[idx++] = u;

        for(int j = 0; j < n; j++)
        {
            if(a[u][j] == 1)
            {
                indegree[j]--;
                if(indegree[j] == 0)
                {
                    top++;
                    s[top] = j;
                }
            }
        }
    }

    printf("The jobs that need to be executed in order are: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", T[i]);
    }
    printf("\n");
}
