#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> // for using 'INT_MAX'

using namespace std;

typedef pair<int, int> node; // <dst node, weight>

struct cmp {
	bool operator()(node a, node b) // <dst node, distance>
	{
		return a.second > b.second;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;

	vector<vector<node>> graph_map(V + 1);
	vector<bool> visited;
	visited.assign(V + 1, false);

	int start_node;
	cin >> start_node;

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w; 
		// u->v with weight w
		// with direction
		graph_map[u].push_back(make_pair(v, w)); 
	}
	
	// initialize distance vector
	// start_node -> 0, otherwise -> INT_MAX
	vector<int> distance;
	distance.assign(V + 1, INT_MAX);
	distance[start_node] = 0;


	priority_queue<node, vector<node>, cmp> p_queue;
	p_queue.push(make_pair(start_node, distance[start_node]));
	while (p_queue.empty() == false)
	{
		node curr = p_queue.top();
		p_queue.pop();

		int curr_node = curr.first;
		int curr_distance = curr.second;
		if (visited[curr_node] == true)
			continue;
		else
		{
			visited[curr_node] = true;
		}

		for (int i = 0; i < graph_map[curr_node].size(); i++)
		{
			node next = graph_map[curr_node].at(i);
			int next_node = next.first;
			int next_distance = next.second;
			
			if (curr_distance + next_distance < distance[next_node])
			{
				distance[next_node] = curr_distance + next_distance;
				p_queue.push(make_pair(next_node, distance[next_node]));
			}
		}
	}

	for (int i = 1; i < distance.size(); i++)
	{
		if (distance[i] == INT_MAX)
			cout << "INF" << "\n";
		else
			cout << distance[i] << "\n";
	}
	return 0;
}