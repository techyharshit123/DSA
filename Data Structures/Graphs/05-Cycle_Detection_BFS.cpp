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

	bool isCycle()
	{
		vector<int>visited(vertices, 0);

		for (int i = 0; i < vertices; i++)
		{
			if (!visited[i])
			{
				queue<pair<int, int>>qu;
				qu.push({i, -1});
				visited[i] = 1;
				while (!qu.empty())
				{
					int node = qu.front().first;
					int parent = qu.front().second;
					qu.pop();

					for (auto neighbour : adj[node])
					{
						if (!visited[neighbour])
						{
							visited[neighbour] = 1;
							qu.push({neighbour, node});
						}
						else
						{
							if (neighbour != parent)
								return true;
						}
					}
				}
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