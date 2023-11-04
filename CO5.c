#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list (used for adjacency lists)
struct Node {
    int data;           // Data (vertex number)
    struct Node* next;  // Pointer to the next node in the list
};

// Structure for the Graph
struct Graph {
    int V; // Number of vertices
    struct Node** adjList; // Array of adjacency lists
};

// Function to create a new node with the given data
struct Node* creatNod(int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty graph with V vertices
struct Graph* creatEm(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = malloc(V * sizeof(struct Node*));
    int i;
    for (i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge between two vertices (undirected graph)
void add(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newN = creatNod(dest);
    newN->next = graph->adjList[src];
    graph->adjList[src] = newN;

    // Since it's an undirected graph, add an edge from dest to src as well
    newN = creatNod(src);
    newN->next = graph->adjList[dest];
    graph->adjList[dest] = newN;
}

// Function to print the graph's adjacency lists
void print(struct Graph* graph) {
	int v;
    for (v = 0; v < graph->V; v++) {
        struct Node *temp = graph->adjList[v];
        printf("Adjacency list of vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int V = 4; // Number of vertices
    struct Graph* grap = creatEm(V);
    
    // Add edges to the graph
    add(grap, 0, 1);
    add(grap, 0, 2);
    add(grap, 1, 2);
    add(grap, 2, 3);
    
    // Print the adjacency lists of the graph
    print(grap);

    return 0;
}

/*
         overview
The code demonstrates how to represent and work with an undirected graph,
using adjacency lists.
It creates the graph structure, adds edges, and displays the adjacency lists. 
*/

/*
		the time complexity of each part:-
      
    Creating the Graph:
   - The "createGraph" function has a time complexity of O(V), where V is the number of vertices.
   - The loop within "createGraph" that initializes adjacency lists runs in O(V) time.

	Adding Edges ("add"):
   - Adding an edge between two vertices is an O(1) operation because,
    it involves creating a new node and updating the adjacency lists for two vertices.
	It does not depend on the number of vertices but rather the number of edges.

	Printing the Graph ("print"):
   - Printing the adjacency lists of all vertices requires visiting each vertex and
    its associated adjacency list.
   - In the worst case,
    it has a time complexity of O(V + E),
	where V is the number of vertices and E is the number of edges in the graph.

	Overall,
	the time complexity of your program primarily depends on the number of vertices (V) and edges (E) in your graph.
	The time complexity of graph algorithms we may apply to the graph, such as traversal or searching, will depend on the specific algorithm used.  
*/
//                  ~chamanswami
