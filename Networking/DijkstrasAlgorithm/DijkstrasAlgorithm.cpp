#include <iostream>
#include <vector>
#include<string>
#include <set>
#include <list>
#include <climits>
using namespace std;

class Graph {
private:
	unsigned V; // number of vertices
	list<pair<int, int>>* adj_list;
public:
	Graph(unsigned);
	~Graph();
	void add_edge(int, int, int);
	void shortest_path(int, int);
};

Graph::Graph(unsigned _V)
{
	V = _V; // the underscore indicates that variable is used once
	adj_list = new list<pair<int, int>>[V];
}

Graph::~Graph()
{
	delete[] adj_list;
}

void Graph::add_edge(int u, int v, int w)
{
	/* a undirected graph */
	adj_list[u].push_back(make_pair(v, w));
	adj_list[v].push_back(make_pair(u, w));
}

void Graph::shortest_path(int src, int dest)
{
	vector<int> predecessors(V); // stores each nodes previous node that flows into it
	vector<char> predecessorPath; // backtracks a node to the source
	unsigned int pIndex = dest - 1;// predecessor index of the nodes starting at the destination 
	set<pair<int, int>> bucket;

	vector<int> dist(V, INT_MAX);

	bucket.insert(make_pair(0, src));
	dist[src] = 0;

	while (bucket.size()) {
		pair<int, int> tmp = *(bucket.begin());
		bucket.erase(bucket.begin());

		int u = tmp.second;

		for (auto& it : adj_list[u])
		{
			int v = it.first;
			int w = it.second;

			if (dist[v] > dist[u] + w)
			{
				if (dist[v] != INT_MAX)
					bucket.erase(bucket.find(make_pair(dist[v], v)));

				dist[v] = dist[u] + w;
				predecessors[v] = u;
				bucket.insert(make_pair(dist[v], v));
			}
		}
	}

	// string letters = { "abcdef" };
	cout << "Vertex    SPD\n";
	for (unsigned i = 0; i < V; i++)
		cout << "  " << (char)('a' + i) << "        " << dist[i] << '\n';
	cout << "\n\n";

	while (pIndex != 0)
	{

		if (pIndex == dest - 1 && predecessors[pIndex] == dest)
		{
			predecessorPath.push_back('a' + pIndex);
			pIndex = dest;
		}
		else
		{
			predecessorPath.push_back('a' + pIndex);
			dest = predecessors[pIndex];
			pIndex = dest;

		}
	}

	predecessorPath.push_back('a'); // insert the source after 
	reverse(predecessorPath.begin(), predecessorPath.end());
	for (unsigned i = 0; i < predecessorPath.size(); i++)
	{
		cout << predecessorPath[i] << ", ";

	}
	cout << "\n";
}

int main(void)
{
	int V = 6;
	Graph g(V);
	/* original
	g.add_edge(0, 1, 4);
	g.add_edge(0, 7, 8);
	g.add_edge(1, 2, 8);
	g.add_edge(1, 7, 11);
	g.add_edge(2, 3, 7);
	g.add_edge(2, 8, 2);
	g.add_edge(2, 5, 4);
	g.add_edge(3, 4, 9);
	g.add_edge(3, 5, 14);
	g.add_edge(4, 5, 10);
	g.add_edge(5, 6, 2);
	g.add_edge(6, 7, 1);
	g.add_edge(6, 8, 6);
	g.add_edge(7, 8, 7);
	*/
	//selva's graph

	g.add_edge(0, 5, 14); // a, f, 14
	g.add_edge(0, 2, 9);  //'a', 'c', 9
	g.add_edge(0, 1, 7);  //'a', 'b', 7
	///////////////////////////////
	g.add_edge(2, 3, 11); //'c', 'd', 11
	g.add_edge(2, 5, 2); //'c', 'f', 2
	g.add_edge(2, 0, 9); //'c', 'a', 9
	g.add_edge(2, 1, 10); //'c', 'b', 10

	//////////////////////////////
	g.add_edge(1, 3, 15); //'b', 'd', 15
	g.add_edge(1, 0, 7); //'b', 'a', 7
	g.add_edge(1, 2, 10); //'b', 'c', 10
	///////////////////////////////
	g.add_edge(4, 3, 6); //'e', 'd', 6
	g.add_edge(4, 5, 9); //'e', 'f', 9
	///////////////////////////////
	g.add_edge(3, 2, 11); //'d', 'c', 11
	g.add_edge(3, 4, 6); //'d', 'e', 6
	g.add_edge(3, 1, 15); //'d', 'b', 15
	//////////////////////////////
	g.add_edge(5, 0, 14); // 'e', 'a', 14
	g.add_edge(5, 2, 2); // 'e', 'c', 2
	g.add_edge(5, 4, 9); // 'e', 'e', 9
	g.shortest_path(0, 5);

	system("pause");
	return 0;
}
