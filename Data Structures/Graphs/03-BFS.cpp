#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int vertices;

	//Array of vectors of size V, V vectors are there
	vector <pair<int, int>> *adj;

	Graph(int V)
	{
		vertices = V;
		adj = new vector <pair<int, int>>[V];
	}

	// adding edges
	void addEdge(int u, int v , bool bidir = true, int wt = 0)
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
			cout << "\n Adjacency list of vertex "
			     << i << "\n head ";
			for (auto x : adj[i]) {
				cout << "-> (" << x.first << ", " << x.second << ") ";
			}
			cout << endl;
		}
	}

	void bfs(int src, int vertices)
	{
		queue<int>q;
		vector<bool>visited(vertices, false);

		q.push(src);
		visited[src] = true;

		while (!q.empty())
		{
			int currentNode = q.front();
			q.pop();

			cout << currentNode << " ";

			for (auto neighbour : adj[currentNode])
			{
				if (not visited[neighbour.first])
				{
					q.push(neighbour.first);
					visited[neighbour.first] = true;
				}
			}
		}
	}
};

int main()
{
	Graph g(5);
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.addEdge(3,5);
	g.addEdge(4,5);
	g.addEdge(3,4);
	g.printadj();

	g.bfs();
}