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

	void toposort(int src, stack<int>&st, vector<int>&visited)
	{
		visited[src] = 1;
		for (auto neighbour : adj[src])
		{
			if (!visited[neighbour])
			{
				toposort(neighbour, st, visited);
			}
		}
		st.push(src);
	}
	vector<int> findToposort()
	{
		vector<int>visited(vertices, 0);
		stack<int>st;
		for (int i = 0; i < vertices; i++)
		{
			if (!visited[i])
			{
				toposort(i, st, visited);
			}
		}

		vector<int>topo;
		while (st.size())
		{
			topo.push_back(st.top());
			st.pop();
		}

		return topo;
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