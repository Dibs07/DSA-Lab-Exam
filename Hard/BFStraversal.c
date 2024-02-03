#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define Max 50

typedef struct Graph
{
    int val;
    bool adj[Max][Max];
} Graph;

Graph *createGraph(int val)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->val = val;
    for (int i = 0; i < val; i++)
    {
        for (int j = 0; j < val; j++)
        {
            g->adj[i][j] = false;
        }
    }
    return g;
}

void createEdge(Graph *g, int v, int w)
{
    g->adj[v][w] = true;
}
void BFS(Graph *g, int s)
{
    bool vis[Max];
    for (int i = 0; i < g->val; i++)
    {
        vis[i] = false;
    }
    int q[Max];
    int front = 0, rear = 0;
    vis[s] = true;
    q[rear++] = s;

    while (front != rear)
    {
        s = q[front++];
        printf("%d ", s);
        for (int adjacent = 0; adjacent < g->val;
             adjacent++)
        {
            if (g->adj[s][adjacent] && !vis[adjacent])
            {
                vis[adjacent] = true;
                q[rear++] = adjacent;
            }
        }
    }
}

int main()
{

    Graph *g = createGraph(4);
    createEdge(g, 0, 1);
    createEdge(g, 0, 2);
    createEdge(g, 1, 2);
    createEdge(g, 2, 0);
    createEdge(g, 2, 3);
    createEdge(g, 3, 3);

    printf("Breadth First Traversal \n");
    BFS(g, 0);

    return 0;
}
