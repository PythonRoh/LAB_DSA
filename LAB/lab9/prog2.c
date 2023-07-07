#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {

	// No. of vertices
	int V;
	int adj[MAX_VERTICES][MAX_VERTICES];
    int a[MAX_VERTICES];
} Graph;

// Constructor
Graph* Graph_create(int V)
{
	Graph* g = malloc(sizeof(Graph));
	g->V = V;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			g->adj[i][j] = 0;
		}
	}

	return g;
}

// Destructor
void Graph_destroy(Graph* g) { free(g); }

// Function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w)
{
	// Add w to v’s list.
	g->adj[v][w] = 1;
}

void delEdge(Graph *g,int a,int b)
{
    g->adj[a][b]=0;
    g->adj[b][a]=0;
    g->V--;
}
void delVertex(Graph *g,int x)
{
    if(x>g->V)
 {       printf("Vertex Not Present\n");
        return;
}
else
{
    int i;
    int n=g->V;
    for (i = 0; i < n; i++) {
        if (g->a[i] == x) {
            break;
        }
    }
 
    // If x found in array
    if (i < n) {
        // reduce size of array and move all
        // elements one space ahead
        n = n - 1;
        for (int j = i; j < n; j++) {
           g->a[j] = g->a[j + 1];
        }
    }
    while(x<g->V)
    {
        for(i=0;i<g->V;i++)
        {
            g->adj[i][x]=g->adj[i][x+1];
        }
        for(i=0;i<g->V;i++)
        {
            g->adj[x][i]=g->adj[x+1][i];
        }
        x++;
    
   
}
g->V--;
}
}
char color1[MAX_VERTICES];
 int parent1[MAX_VERTICES];
int d[MAX_VERTICES];
int f[MAX_VERTICES];
int time;
void DFS_VISIT(Graph* g, int u)
{
    int i,j,l=0,o=0;
    color1[u] = 'y';
    d[u]=time+1;
    time++;
    printf("%d ",g->a[u]);
    for (int v = 0; v < g->V; v++) {
        if (color1[v]=='w' && g->adj[u][v]) {
            parent1[v]=u;
            DFS_VISIT(g, v);
        }
    }
    color1[u]='r';
    f[u]=time+1;
    time++;
}
 
// Function for DFS traversal
void DFS(Graph* g)
{
    for (int i = 0; i < g->V; i++) {
        color1[i] = 'w';
        parent1[i]=-1;
    }
    for (int i = 0; i < g->V; i++) {
        if (color1[i]=='w') {
            DFS_VISIT(g, i);
        }
    }
    
}
void Graph_BFS(Graph* g, int s)
{
	// Mark all the vertices as not visited
	char color[MAX_VERTICES];
    int parent[MAX_VERTICES];
    int dist[MAX_VERTICES];
	for (int i = 0; i < g->V; i++) {
		color[i] = 'w';
        parent[i]=0;
        dist[i]=0;
	}

	// Create a queue for BFS
	int queue[MAX_VERTICES];
	int front = 0, rear = 0;

	// Mark the current node as visited and enqueue it
	color[s] = 'y';
	queue[rear++] = s;

	while (front != rear) {

		// Dequeue a vertex from queue and print it
		s = queue[front++];
		// Get all adjacent vertices of the dequeued
		// vertex s.
		// If an adjacent has not been visited,
		// then mark it visited and enqueue it
		for (int adjacent = 0; adjacent < g->V;
			adjacent++) {
			if (g->adj[s][adjacent] && color[adjacent]=='w') {
				color[adjacent] = 'y';
                dist[adjacent]=dist[s]+1;
                parent[adjacent]=s;
				queue[rear++] = adjacent;
			}
            
        color[s]='r';
		
		}
        printf("%d \n", g->a[s]);
       
	}
    
}
// Driver code
int main()
{
    
	// Create a graph
	Graph* g = Graph_create(6);
    for(int i=0;i<7;i++)
    {
        g->a[i]=i;
    }
	Graph_addEdge(g,0,1);
	Graph_addEdge(g,1,2);
	Graph_addEdge(g,1,3);
	Graph_addEdge(g, 2, 1);
	Graph_addEdge(g, 1, 0);
	Graph_addEdge(g, 3, 1);
    Graph_addEdge(g, 3, 2);
    Graph_addEdge(g, 2, 3);
    Graph_addEdge(g, 3, 4);
    Graph_addEdge(g, 4, 3);
    Graph_addEdge(g, 4, 5);
    Graph_addEdge(g, 5, 4);
    delVertex(g,0);
    delEdge(g,4,5);
    printf("Following is Breadth First Traversal starting from vertex 1 \n");
	Graph_BFS(g, 1);
    printf("Following is Depth First Traversal  \n");
	DFS(g);
	Graph_destroy(g);

	return 0;
}