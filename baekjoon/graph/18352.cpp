#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


vector<int> answer;
void bfs(vector<vector<int>> &map, vector<bool> &visited, int start_node, int required_distance)
{
	queue<pair<int, int>> city_list; // (node_idx, depth)
	int start_depth = 0;
	city_list.push(make_pair(start_node, start_depth));
	visited[start_node] = true;

	while (city_list.empty() == false)
	{
		int curr_node = city_list.front().first;
		int curr_depth = city_list.front().second;
		if (curr_depth == required_distance)
		{
			answer.push_back(curr_node);
		}

		for (int i = 0; i < map[curr_node].size(); i++)
		{
			int next_node = map[curr_node].at(i);
			int next_depth = curr_depth + 1;
			if (visited[next_node] == false)
			{
				city_list.push(make_pair(next_node, next_depth));
				visited[next_node] = true;
			}
		}
		city_list.pop();
	}
}
int main()
{
	int N, M, K, start_node;

	cin >> N >> M >> K >> start_node;

	vector<vector<int>> city_map(N + 1);
	vector<bool> visited;
	visited.assign(N + 1, false);
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		city_map[A].push_back(B);
	}

	bfs(city_map, visited, start_node, K);
	sort(answer.begin(), answer.end());

	if (answer.empty() == true)
	{
		cout << -1;
	}
	else
	{
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << "\n";
		}
	}
	

	return 0;
}