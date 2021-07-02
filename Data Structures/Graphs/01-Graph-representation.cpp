#include <bits/stdc++.h>
using namespace std;



void printGraph(vector<int> adj[], int V) //V is number of vertices
{
	for (int v = 0; v < V; ++v)
	{
		cout << "\n Adjacency list of vertex "
		     << v << "\n head ";
		for (auto x : adj[v])
			cout << "-> " << x;
		printf("\n");
	}
}

// *******************************************ADJACENCY LIST*****************************
// Undirected graph
int main()
{
	int n, m; // n is number of vertices and m is number of edges
	cin >> n >> m;

	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

// Directed Graph
int main()
{
	int n, m; // n is number of vertices and m is number of edges
	cin >> n >> m;

	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v; // u and v are nodes

		adj[u].push_back(v);
	}
}

// Weighted Graph(Undirected)
int main()
{
	int n, m; // n is number of vertices and m is number of edges
	cin >> n >> m;

	vector<pair<int, int>> adj[n + 1];
	for (int i = 0; i < m; i++)
	{
		int u, v, wt;  //wt is the weight of the ith edge
		cin >> u >> v >> wt;

		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}
}


// *******************************************ADJACENCY MATRIX*****************************
int main()
{
	int n, m;
	cin >> n >> m;

	// declare the adjacency matrix
	int adj[n + 1][n + 1];

	// take edges as input
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u][v] = 1;
		adj[v][u] = 1;
	}
}