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
	int shortestPath(int src)
	{
		vector<int>distance(vertices, INT_MIN);
		queue<int>qu;

		qu.push(src); // push the 0th node in queue
		distance[src] = 0; // as the distance of reaching src from src is 0

		while (qu.size())
		{
			int front = qu.front();
			qu.pop();
			int dist = distance[front];
			for (auto neighbour : adj[front])
			{
				if (distance[neighbour] > dist + 1)
				{
					qu.push(neighbour);
					distance[neighbour] = dist + 1;
				}
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