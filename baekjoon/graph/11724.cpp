#include <iostream>
#include <vector>

using namespace std;


void dfs(vector<vector<int>> &my_graph, vector<bool>& visited, int start_node)
{
    visited[start_node] = true;

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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> my_graph;
    vector<bool> visited;
    my_graph.resize(N + 1);
    visited.assign(N+1, false);
    
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        my_graph[u].push_back(v);
        my_graph[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == false)
        {
            dfs(my_graph, visited, i);
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}