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
        for (int i = 0; i < g->val;i++)
        {
            if (g->adj[s][i] && !vis[i])
            {
                vis[i] = true;
                q[rear++] = i;
            }
        }
    }
}

void DFSUtil(Graph *g, int v, bool vis[])
{
    vis[v] = true;
    printf("%d ", v);

    for (int i = 0; i < g->val; i++)
    {
        if (g->adj[v][i] && !vis[i])
        {
            DFSUtil(g, i, vis);
        }
    }
}

void DFS(Graph *g, int s)
{
    bool vis[Max];
    for (int i = 0; i < g->val; i++)
    {
        vis[i] = false;
    }

    DFSUtil(g, s, vis);
}


int main()
{

    Graph *g = createGraph(8);
     createEdge(g,0, 1);    
        createEdge(g,0, 2);    
        createEdge(g,0, 3);    
        createEdge(g,1, 3);    
        createEdge(g,2, 4);  
        createEdge(g,3, 5);       
        createEdge(g,3, 6);    
        createEdge(g,4, 7);    
        createEdge(g,4, 5);    
        createEdge(g,5, 2);    

    printf("Breadth First Traversal \n");
    BFS(g, 0);
    printf("\n");

    printf("Depth First Traversal \n");
    DFS(g,0);

    return 0;
}
