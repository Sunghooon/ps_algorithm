#include <iostream>
#include <vector>

using namespace std;

int find(int i, vector<int>& parent)
{
    if (parent[i] == i)
    {
        return i;
    }
    else
    {
        return parent[i] = find(parent[i], parent);
    }
}
void unionfunc(int a, int b, vector<int>& parent)
{
    a = find(a, parent);
    b = find(b, parent);

    if (a != b)
    {
        parent[b] = a;
    }

}
int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> party(M);
    vector<int> parent(N + 1);
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    int n_true;
    cin >> n_true;
    vector<int> true_member(n_true);

    for (int i = 0; i < n_true; i++)
    {
        int _in;
        cin >> _in;
        true_member[i] = _in;
    }

    for (int i = 0; i < M; i++)
    {
        int n_person;
        cin >> n_person;
        for (int j = 0; j < n_person; j++)
        {
            int p;
            cin >> p;
            party[i].push_back(p);
        }
    }


    // let true_member be grouped
    for (int i = 0; i < n_true - 1; i++)
    {
        unionfunc(true_member[i], true_member[i + 1], parent);
    }

    // make every party be grouped
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < party[i].size() - 1; j++)
        {
            unionfunc(party[i].at(j), party[i].at(j + 1), parent);
        }
    }

    // check
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        if (true_member.empty() == false)
        {
            if (find(true_member[0], parent) == find(party[i].at(0), parent))
            {
                continue;
            }
            else
            {
                cnt++;
            }
        }
        else
            cnt++;
    }

    cout << cnt;
    return 0;
}