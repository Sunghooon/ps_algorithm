#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> schedule_table(N+1);
    for(int i = 1; i <= N; i++)
    {
        int time_cost, value;
        cin >> time_cost >> value;
        schedule_table[i] = make_pair(time_cost, value);
    }

    vector<int> dp(N+2);
    dp[N+1] = 0;
    for(int i = N; i >= 1; i--)
    {
        if(i + schedule_table[i].first >= N+2)
        {
            dp[i] = dp[i+1];
        }
        else
        {
            dp[i] = max(dp[i+1], dp[i + schedule_table[i].first] + schedule_table[i].second);
        }
    }
    cout << dp[1];
    return 0;
}