// An Iterative C++ program to do DFS traversal from
// a given source vertex. DFS(int s) traverses vertices
// reachable from s.
#include<bits/stdc++.h>
using namespace std;
 
// This class represents a directed graph using adjacency
// list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // to add an edge to graph
    void DFS(int s);  // prints DFS from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
// Function to print all vertices reachable from 's'
// using iterative DFS.
void Graph::DFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a stack for DFS
    stack<int> stack;
 
    // Mark the current node as visited and push it
    visited[s] = true;
    stack.push(s);
 
    // 'i' will be used to get all adjacent vertices
    // of a vertex
    list<int>::iterator i;
 
    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        cout << s << " ";
        stack.pop();
 
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then mark it
        // visited and push it to the stack
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                stack.push(*i);
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(5);  // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
 
    cout << "Following is Depth First Traversal "
            "(starting from vertex 0) \n";
    g.DFS(0);
 
    return 0;
}
