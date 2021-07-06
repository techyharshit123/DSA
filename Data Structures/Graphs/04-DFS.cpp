#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int vertices;
	//Array of vectors of size V, V vertices are there
	vector <pair<int, int>> *adj;

	Graph(int V)
	{
		vertices = V;
		adj = new vector <pair<int, int>>[V];
	}

	void addEdge(int u, int v, bool bidir = true, int wt = 0)
	{
		adj[u].push_back({v, wt});
		if (bidir) {
			adj[v].push_back({u, wt});
		}
	}

	void printadj()
	{
		for (int i = 0; i < vertices; i++)
		{
			cout << "Adjacency List of vertex " << i << " is := ";
			for (auto neighbour : adj[i])
				cout << neighbour.first << " -> ";
			cout << endl;
		}
	}
	void dfshelper(int i, vector<bool>&visited, vector<int>&dfsarray)
	{
		for (auto neighbour : adj[i])
		{
			if (!visited[neighbour.first])
			{
				cout << neighbour.first << " ";
				visited[neighbour.first] = true;
				dfsarray.push_back(neighbour.first);
				dfshelper(neighbour.first, visited, dfsarray);
			}
		}
	}
	void dfs(int src)
	{
		vector<bool>visited(vertices, false);
		vector<int>dfsarray(vertices);

		for (int i = 0; i < vertices; i++)
		{
			if (!visited[i])
			{
				cout << i << " ";
				visited[i] = true;
				dfsarray.push_back(i);
				dfshelper(i, visited, dfsarray);
			}
		}
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
	g.dfs(0);

}
