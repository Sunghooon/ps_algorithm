#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int N, M;
int map[50][50];
int visited[50][50];
void init_visit()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }
}
int bfs(int i, int j)
{
    int init_depth = 0;
    visited[i][j] = true;
    queue<tuple<int, int, int>> my_queue; // <i, j, depth>
    my_queue.push(make_tuple(i, j, init_depth));

    while (my_queue.empty() == false)
    {
        int curr_i = get<0>(my_queue.front());
        int curr_j = get<1>(my_queue.front());
        int curr_depth = get<2>(my_queue.front());

        if (map[curr_i][curr_j] == 1) // shark
        {
            return curr_depth;
        }
        else
        {
            for (int n = 0; n < 8; n++) // 8 directions
            {
                int nj = curr_j + dx[n];
                int ni = curr_i + dy[n];
                if (nj >= 0 && ni >= 0 && ni < N && nj < M)
                {
                    if (visited[ni][nj] == false)
                    {
                        visited[ni][nj] = true;
                        my_queue.push(make_tuple(ni, nj, curr_depth + 1));
                    }
                }
            }
        }
        my_queue.pop();
    }

}
int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    int max_safety = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            init_visit();
            max_safety = max(max_safety, bfs(i, j));
        }
    }

    cout << max_safety;
    return 0;
}