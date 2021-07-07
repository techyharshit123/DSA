#include <bits/stdc++.h>
using namespace std;

// T denotes any general type -> later we'll replace T with int/float/string etc
template<typename T>
class Graph
{
public:
	unordered_map<T, list<pair<T, int>>>adj;
	Graph() {} // constructor
	void addEdge()
};