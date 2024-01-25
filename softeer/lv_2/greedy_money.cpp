// https://softeer.ai/practice/6288
// greedy algorithm
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int main()
{
    int W, N;
    cin >> W >> N;

    vector<pair<int, int>> my_bag; // <weight, price>
    for(int i = 0; i < N; i++)
    {
        int m, p;
        cin >> m >> p;
        my_bag.push_back(make_pair(m, p));
    }
    sort(my_bag.begin(), my_bag.end(), compare);

    int ans_price = 0;
    for(int i = 0; i < N; i++)
    {
        if(W > 0)
        {
            if(W > my_bag[i].first)
            {
                W -= my_bag[i].first;
                ans_price += my_bag[i].first * my_bag[i].second;
            }
            else
            {
                ans_price += W * my_bag[i].second;
                W = 0;
            }
        }
        else
        {
            break;
        }
    }
    cout << ans_price;

    return 0;
}