//Graph Traversal using DFS and BFS
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_NODES];
    int visited[MAX_NODES];
};

// Queue for BFS
struct Queue {
    int items[MAX_NODES];
    int front;
    int rear;
};

// Function prototypes
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void DFS(struct Graph* graph, int vertex);
void BFS(struct Graph* graph, int startVertex);
struct Queue* createQueue();
void enqueue(struct Queue* q, int value);
int dequeue(struct Queue* q);
int isEmpty(struct Queue* q);
void resetVisited(struct Graph* graph);

// Create Graph
struct Graph* createGraph(int vertices) {

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Undirected graph
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS Traversal
void DFS(struct Graph* graph, int vertex) {

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adjLists[vertex];

    while (temp != NULL) {

        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }

        temp = temp->next;
    }
}

// Create Queue
struct Queue* createQueue() {

    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

    q->front = -1;
    q->rear = -1;

    return q;
}

// Check empty
int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

// Enqueue
void enqueue(struct Queue* q, int value) {

    if (q->rear == MAX_NODES - 1) {
        printf("\nQueue is full!");
    }
    else {

        if (q->front == -1)
            q->front = 0;

        q->rear++;

        q->items[q->rear] = value;
    }
}

// Dequeue
int dequeue(struct Queue* q) {

    int item;

    if (isEmpty(q)) {
        printf("\nQueue is empty!");
        return -1;
    }
    else {

        item = q->items[q->front];
        q->front++;

        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }

        return item;
    }
}

// BFS Traversal
void BFS(struct Graph* graph, int startVertex) {

    struct Queue* q = createQueue();

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {

        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp != NULL) {

            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {

                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }

            temp = temp->next;
        }
    }
}

// Reset visited
void resetVisited(struct Graph* graph) {

    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}

// Main
int main() {

    int vertices, edges, src, dest, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source and destination):\n");

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("Depth First Search starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex);

    resetVisited(graph);

    printf("\n\nEnter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("Breadth First Search starting from vertex %d:\n", startVertex);
    BFS(graph, startVertex);

    return 0;
}