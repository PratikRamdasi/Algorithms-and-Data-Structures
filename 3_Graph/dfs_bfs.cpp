/*
 * Author: Pratik Ramdasi
 * 
 * Date: 04/09/2017
 * 
 * Title: Graph Traversal - DFS, BFS
 */
  
// C++ Program to print DFS traversal and BFS traversal from a givan vertex in the graph
#include <iostream> 
#include <list>

using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph
{
	int V;  // number of vartices
	list<int> *adj; // pointer to array containing adjacency lists
	void DFSUtil(int v, bool visited[]); // function used by DFS
	
	public: 
		Graph(int V); // constructor
		void addEdge(int v, int w); // function to add edge in the graph
		void DFS(int v); // DFS traversal from vertex v
		void BFS(int s); // BFS traversal from source s
		
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) 
{
	adj[v].push_back(w); // add w to v's list
}
	
void Graph::DFSUtil(int v, bool visited[])
{
	// mark current node visited and print it
	visited[v] = true;
	cout << v << " ";
	
	// Recur for all the vertices adjacent to it
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {
		if(!visited[*i]) {
			DFSUtil(*i, visited);
		}
	} 
}

void Graph::DFS(int v)
{
	// mark all the vertices not visited
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++) {
		visited[i] = false;
	}
	// call DFSUtil function to print DF traversal
	DFSUtil(v, visited);
}

void Graph::BFS(int s)
{
	// mark all vertices not visited
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++) {
		visited[i] = false;
	}
	
	// create queue for BFS
	list<int> queue;
	
	// mark current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);
	
	// 'i' used to get all adjacent vertices
	list<int>::iterator i;
	
	while(!queue.empty()) 
	{	
		// dequeue vertex and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		
		// get all adjacent vertices of s 
		// if adjacent is not visited, mark it visited and enqueue it
		for (i = adj[s].begin(); i != adj[s].end(); ++i) 
		{
			/* check if node is reachable - bool isReachable(int s, int d)
			 * if (*i == d) 
			 * 		return true;
			 */ 
			
			if (! visited[*i]) 
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	} 
	
	/* return false; */
}
	

int main()
{
	// create graph
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	
	cout << "DF traversal from vertex 2 - ";
	g.DFS(2);
	cout << endl;
	cout << "BF traversal from vertex 2 - ";
	g.BFS(2);
	cout << endl;
	
	return 0;
}
	
	
