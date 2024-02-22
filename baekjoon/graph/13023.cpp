#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool required_depth = false;
vector<vector<int>> friends;
vector<bool> visited;
void dfs(int curr_node, int curr_depth)
{
    visited[curr_node] = true;
    if(curr_depth >= 5)
    {
        required_depth = true;
        return;
    }

    for(int i = 0; i < friends[curr_node].size(); i++)
    {
        int next_node = friends[curr_node].at(i);
        int next_depth = curr_depth + 1;
        if(visited[next_node] == false)
        {
            dfs(next_node, next_depth);
        }
    }
    visited[curr_node] = false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M;
    
    friends.resize(N);
    visited.assign(N, false);

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    for(int i = 0; i < N; i++)
    {
        if(required_depth == false)
        {
            dfs(i, 1);
        }
    }
    if(required_depth == true) cout << 1;
    else cout << 0;

    return 0;
}