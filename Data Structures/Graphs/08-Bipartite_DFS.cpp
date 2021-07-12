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
		adj = new vector<int>[V];
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

	bool BipartiteDFS(int src, vector<int>&colour)
	{
		for (auto neighbour : adj[src])
		{
			if (colour[neighbour] == -1)
			{
				colour[neighbour] = !colour[src];
				BipartiteDFS(neighbour, colour);
			}
			else
			{
				if (colour[neighbour] == colour[src])
					return false;
			}
		}
		return true;
	}

	bool isBipartite()
	{
		vector<int>colour(vertices, -1);

		for (int i = 0; i < vertices; i++) // if any of the components is not bipartite then the entire graph is not bipartite
		{
			if (colour[i] == -1)
			{
				colour[i] = 0; //colouring intial node with colour 0
				if (!BipartiteDFS(i, colour))
					return false;
			}
		}
		return true;
	}

}

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