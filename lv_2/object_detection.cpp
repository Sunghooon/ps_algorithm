// https://softeer.ai/practice/6282
// bfs, exhaustive search 
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool visited[25][25] = { false, };
int map[25][25] = { 0, };
int bfs(int start_x, int start_y)
{
	int curr_x, curr_y, cnt = 1;
	int max_cnt = -1;
	queue<pair<int, int>> explore_list; // <x, y>
	explore_list.push(make_pair(start_x, start_y));
	visited[start_y][start_x] = true;
	while (explore_list.empty() != true)
	{
		curr_x = explore_list.front().first;
		curr_y = explore_list.front().second;

		for (int i = 0; i < 4; i++)
		{
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				if (map[ny][nx] != 0 && visited[ny][nx] == false)
				{
					cnt++;
					visited[ny][nx] = true;
					explore_list.push(make_pair(nx, ny));
				}
			}
		}
		explore_list.pop();
	}
	return cnt;
}
int main()
{

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			map[i][j] = s[j] - '0';
		}
	}

	int explore_result = 0;
	vector<int> objects;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == false)
			{
				explore_result = bfs(j, i);
				objects.push_back(explore_result);
			}
		}
	}
	sort(objects.begin(), objects.end());
	cout << objects.size() << endl;
	for (int i = 0; i < objects.size(); i++)
	{
		cout << objects[i] << endl;
	}
	return 0;
}