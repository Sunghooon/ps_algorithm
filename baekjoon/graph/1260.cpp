#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


void bfs(vector<vector<int>>& my_graph, vector<bool>& visited, int start_node)
{
    queue<int> my_queue;
    my_queue.push(start_node);
    visited[start_node] = true;

    while (my_queue.empty() == false)
    {
        int curr_node = my_queue.front();
        for (int i = 0; i < my_graph[curr_node].size(); i++)
        {
            int next_node = my_graph[curr_node].at(i);
            if (visited[next_node] == false)
            {
                visited[next_node] = true;
                my_queue.push(next_node);
            }
        }
        cout << my_queue.front() << " ";
        my_queue.pop();
    }

}
void dfs(vector<vector<int>>& my_graph, vector<bool>& visited, int start_node)
{
    visited[start_node] = true;
    cout << start_node << " ";

    sort(my_graph[start_node].begin(), my_graph[start_node].end());
    for (int i = 0; i < my_graph[start_node].size(); i++)
    {
        int next_node = my_graph[start_node].at(i);
        if (visited[next_node] == false)
        {
            dfs(my_graph, visited, next_node);
        }
    }
}
int main()
{
    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> my_graph;
    vector<bool> visited;

    my_graph.resize(N + 1);
    visited.assign(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        my_graph[u].push_back(v);
        my_graph[v].push_back(u);
    }

    dfs(my_graph, visited, V);
    cout << "\n";
    visited.assign(N + 1, false);
    bfs(my_graph, visited, V);

    return 0;
}