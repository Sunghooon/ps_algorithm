#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

typedef pair<int, int> node;
struct cmp {
    bool operator()(node& a, node& b)
    {
        return a.second > b.second;
    }
};
int main()
{
    int N, M;
    cin >> N;
    cin >> M;

    vector<vector<node>> city_map(N + 1); // <city, cost>
    vector<bool> visited;
    visited.assign(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        city_map[start].push_back(make_pair(end, cost));
    }
    int start, end;
    cin >> start >> end;

    vector<int> min_dist(N + 1);
    min_dist.assign(N + 1, INT_MAX);

    min_dist[start] = 0;
    priority_queue<node, vector<node>, cmp> pq;
    pq.push(make_pair(start, min_dist[start]));

    while (pq.empty() == false)
    {
        int curr_city = pq.top().first;
        int curr_cost = pq.top().second;
        if (visited[curr_city] == true)
        {
            pq.pop();
            continue;
        }
        visited[curr_city] = true;
        pq.pop();
        for (int i = 0; i < city_map[curr_city].size(); i++)
        {
            int next_city = city_map[curr_city].at(i).first;
            int next_cost = city_map[curr_city].at(i).second;

            if (curr_cost + next_cost < min_dist[next_city])
            {
                min_dist[next_city] = curr_cost + next_cost;
                pq.push(make_pair(next_city, min_dist[next_city]));
            }

        }

    }

    cout << min_dist[end];

    return 0;
}