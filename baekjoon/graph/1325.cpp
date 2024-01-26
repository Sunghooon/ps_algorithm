#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& my_graph, vector<bool>& visited, int start_node)
{
    int cnt = 1;
    visited[start_node] = true;
    queue<int> my_queue;
    my_queue.push(start_node);

    while (my_queue.empty() == false)
    {
        int curr_node = my_queue.front();

        for (int i = 0; i < my_graph[curr_node].size(); i++)
        {
            int next_node = my_graph[curr_node].at(i);
            if (visited[next_node] == false)
            {
                cnt++;
                visited[next_node] = true;
                my_queue.push(next_node);
            }
        }
        my_queue.pop();
    }
    return cnt;
}
int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> my_graph(N + 1);
    vector<bool> visited(N + 1);
    vector<int> cnt(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        my_graph[b].push_back(a);
    }
    int max_val = -1;
    for (int i = 1; i <= N; i++)
    {
        visited.assign(N + 1, false);
        cnt[i] = bfs(my_graph, visited, i);
        max_val = max(cnt[i], max_val);
    }

    for (int i = 1; i <= N; i++)
    {
        if (cnt[i] == max_val)
        {
            cout << i << " ";
        }
    }


    return 0;
}