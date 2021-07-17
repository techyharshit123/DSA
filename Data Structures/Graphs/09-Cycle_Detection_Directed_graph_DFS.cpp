#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int vertices;
	vector<int>*adj;

	Graph(int V)
	{
		vertices = V;
		adj = new vector<int>[V]; //always specify the size of array you are making otherwise it will give runtime error
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void printadj()
	{
		for (int i = 0; i < vertices; i++)
		{
			cout << "Adjacency List of vertex " << i << " is := ";
			for (auto neighbour : adj[i])
				cout << neighbour << " -> ";
			cout << endl;
		}
	}

	bool isCycleHelper(int src, vector<int> dfsvisited, vector<int>&visited)
	{
		visited[src] = 1;
		dfsvisited[src] = 1;
		for (auto neighbour : adj[src])
		{
			if (!visited[neighbour])
			{
				if (isCycleHelper(neighbour, dfsvisited, visited))
					return true;
			}
			else
			{
				if (dfsvisited[neighbour])
					return true;
			}
		}
		dfsvisited[src] = 0;
		return false;
	}
	bool isCycle()
	{
		vector<int>visited(vertices, 0);
		vector<int>dfsvisited(vertices, 0);
		for (int i = 0; i < vertices; i++)
		{
			if (!visited[i])
			{
				if (isCycleHelper(i, dfsvisited, visited))
					return true;
			}
		}
		return false;
	}
};

int main()
{
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(1, 3);
	g.addEdge(1, 2);
	g.addEdge(0, 2);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(2, 3);
	g.printadj();

	cout << g.isCycle() << endl;
}