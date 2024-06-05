#include <iostream>
#include <queue>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
	map<int,bool> visited;
	map<int,list<int>> adj;
	void addEdge(int v,int w);
	void DFS(int v);
};

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::DFS(int v)
{
	visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

void bfs(vector<vector<int> >& adjList, int startNode,
         vector<bool>& visited)
{
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void addEdge(vector<vector<int> >& adjList, int u, int v)
{
    adjList[u].push_back(v);
}

int main()
{
    int vertices = 5;
    int a;
    cin>>a;
    switch (a)
    {
    
    case 1:{

    vector<vector<int> > adjList(vertices);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    vector<bool> visited(vertices, false);

    cout << "Breadth First Traversal starting from vertex "
            "0: ";
    bfs(adjList, 0, visited);
    break;
    }
    case 2:{
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";

	g.DFS(0);}
    }
    return 0;
}
