#include <iostream>

using namespace std;

int calc_area(int a, int b, int c)
{
    int answer = 0;
    int cnt[4] = { 0, };
    cnt[a]++;
    cnt[b]++;
    cnt[c]++;

    if (cnt[1] == 3 || cnt[2] == 3 || cnt[3] == 3)
        return 0;
    else if (cnt[1] == 2)
    {
        if (cnt[2] == 1)
            return 1;
        else
            return 2;
    }
    else if (cnt[2] == 2)
    {
        if (cnt[1] == 1)
            return 1;
        else
            return 2;
    }
    else if (cnt[3] == 2)
    {
        if (cnt[1] == 1)
            return 2;
        else
            return 1;
    }
    else
        return 2;
}
int main()
{
    int map[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> map[i][j];
    }

    int min_cost = 3;
    for (int i = 0; i < 3; i++)
    {
        min_cost = min(min_cost, calc_area(map[i][0], map[i][1], map[i][2]));
    }
    for (int j = 0; j < 3; j++)
    {
        min_cost = min(min_cost, calc_area(map[0][j], map[1][j], map[2][j]));
    }

    cout << min_cost;
    return 0;
}