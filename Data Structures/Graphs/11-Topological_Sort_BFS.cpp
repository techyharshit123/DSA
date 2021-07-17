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
	vector<int> findToposort()
	{
		vector<int>indegree(vertices, 0);

		// forming the indegree vector
		for (int i = 0; i < vertices; i++)
		{
			for (auto neighbour : adj[i])
			{
				indegree[neighbour]++;
			}
		}

		queue<int>qu;
		vector<int>toposort;

		for (int i = 0; i < vertices; i++)
		{
			if (indegree[i] == 0)
			{
				qu.push(i);
			}
		}

		// Now process the queue
		while (qu.size())
		{
			int front = qu.front();
			qu.pop();
			toposort.push_back(front);

			for (auto neighbour : adj[front])
			{
				indegree[neighbour]--;

				if (indegree[neighbour] == 0)
					qu.push(neighbour);
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


}