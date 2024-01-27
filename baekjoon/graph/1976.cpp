#include <iostream>
#include <vector>

using namespace std;

int map[201][201] = { 0, };
int parent[201];

int find_function(int a)
{
    if (parent[a] == a)
    {
        return parent[a];
    }
    else
    {
        return parent[a] = find_function(parent[a]);
    }
}
void union_function(int a, int b)
{
    a = find_function(a);
    b = find_function(b);
   
    if (a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}

int main()
{
    int N; // # of city
    cin >> N;
    int M; // # of city included in plan
    cin >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int a;
            cin >> a;
            map[i][j] = a;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (map[i][j] == 1) // connected
            {
                union_function(i, j);
            }
        }
    }

    bool changed = false;
    int city_id = 0;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        if (i == 0)
            city_id = find_function(a);
        else
        {
            if (city_id != find_function(a))
            {
                changed = true;
                break;
            }
        }
    }
    if (changed == true)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }


    return 0;
}