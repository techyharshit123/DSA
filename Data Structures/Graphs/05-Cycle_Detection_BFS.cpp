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
		adj = new vector<int>;
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

	bool isCycle()
	{
		vector<int>visited(vertices, 0);

		for (int i = 0; i < vertices; i++)
		{
			if (!visited[i])
			{
				queue<pair<int, int>>qu;
				qu.push({adj[i][0], -1});
				visited[i] = 1;
				for (auto neighbour : adj[i])
				{
					int parent = qu.front().first;
					if (!visited[neighbour])
					{
						visited[neighbour] = 1;
						qu.push({neighbour, parent});
					}
					else
					{
						if (visited[neighbour] != parent)
							return true;
					}
				}
			}
		}
		return false;
	}
};