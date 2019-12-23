#include<stdio.h>

int adjMatrix[50][50];
char colourOfVertex[50];
int n;

void dfs(int v)
{
        int i;
        colourOfVertex[v] = 'G';
        printf("%d ", v);
        for(i = 0; i < n; i++)
        {
                if(colourOfVertex[i] == 'W' && adjMatrix[v][i] == 1)
                {
                        dfs(i);
                }
        }
        return;
}

int main()
{
        int i, j;
        printf("Enter the number of vertices: ");
        scanf("%d",&n);
        printf("Enter adjacency matrix:\n");
        for(i = 0; i < n; i++)
        {
                for(j = 0; j < n; j++)
                {
                        scanf("%d", &adjMatrix[i][j]);
                }
        }
        for(i = 0; i < n; i++)
        {
                colourOfVertex[i]='W';
        }
        printf("DFS traversal of graph: ");
        dfs(0);
        printf("\n");
        return 0;
}
