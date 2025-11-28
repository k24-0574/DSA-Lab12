#include <iostream>
using namespace std;

#define MAX 10

struct Node {
    int vertex;
    Node* next;
};

struct Graph {
    int numVertices;
    Node* adjList[MAX];   
    int adjMatrix[MAX][MAX]; 
};

Node* createNode(int v) {
    Node* newNode = new Node;
    newNode->vertex = v;
    newNode->next = nullptr;
    return newNode;
}

void initGraph(Graph &g, int n) {
    g.numVertices = n;
    for(int i=0;i<n;i++){
        g.adjList[i] = nullptr;
        for(int j=0;j<n;j++)
            g.adjMatrix[i][j] = 0;
    }
}

void addEdge(Graph &g, int src, int dest) {
    src--; dest--;

    Node* newNode = createNode(dest);
    newNode->next = g.adjList[src];
    g.adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = g.adjList[dest];
    g.adjList[dest] = newNode;

    
    g.adjMatrix[src][dest] = 1;
    g.adjMatrix[dest][src] = 1;
}


void displayList(Graph &g) {
    cout << "Adjacency List:" << endl;
    for(int i=0;i<g.numVertices;i++){
        cout << i+1 << ": ";
        Node* temp = g.adjList[i];
        while(temp){
            cout << temp->vertex +1 << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void displayMatrix(Graph &g){
    cout << "Adjacency Matrix:" << endl;
    for(int i=0;i<g.numVertices;i++){
        for(int j=0;j<g.numVertices;j++)
            cout << g.adjMatrix[i][j]<< " ";
        cout << endl;
    }
}

void BFS(Graph &g, int start){
    bool visited[MAX] = {false};
    int queue[MAX];
    int front=0, rear=0;

    visited[start] = true;
    queue[rear++] = start;

    cout << "BFS traversal: ";
    while(front < rear){
        int v = queue[front++];
        cout << v+1 << " ";

        Node* temp = g.adjList[v];
        while(temp){
            int u = temp->vertex;
            if(!visited[u]){
                visited[u] = true;
                queue[rear++] = u;
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

void DFSUtil(Graph &g, int v, bool visited[]){
    visited[v] = true;
    cout << v+1 << " ";

    Node* temp = g.adjList[v];
    while(temp){
        int u = temp->vertex;
        if(!visited[u]){
            DFSUtil(g,u,visited);
        }
        temp = temp->next;
    }
}

void DFS(Graph &g, int start){
    bool visited[MAX] = {false};
    cout << "DFS traversal: ";
    DFSUtil(g, start, visited);
    cout << endl;
}

int main(){
    Graph g;
    int n = 5; 
    initGraph(g,n);
    addEdge(g,1, 4);
    addEdge(g,4, 2);
    addEdge(g,5, 3);
    addEdge(g,5,2);
    addEdge(g,5,4);

    displayList(g);
    cout << endl;
    displayMatrix(g);
    cout << endl;

    BFS(g,0);
    DFS(g,0);

    return 0;
}
