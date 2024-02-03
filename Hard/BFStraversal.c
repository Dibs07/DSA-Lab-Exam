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

void Graph_destroy(Graph *g) { free(g); }

void createEdge(Graph *g, int v, int w)
{
    g->adj[v][w] = true;
}
void Graph_BFS(Graph *g, int s)
{
    bool visited[Max];
    for (int i = 0; i < g->val; i++)
    {
        visited[i] = false;
    }
    int queue[Max];
    int front = 0, rear = 0;
    visited[s] = true;
    queue[rear++] = s;

    while (front != rear)
    {
        s = queue[front++];
        printf("%d ", s);
        for (int adjacent = 0; adjacent < g->val;
             adjacent++)
        {
            if (g->adj[s][adjacent] && !visited[adjacent])
            {
                visited[adjacent] = true;
                queue[rear++] = adjacent;
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
    Graph_BFS(g, 0);
    Graph_destroy(g);

    return 0;
}
