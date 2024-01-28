// https://softeer.ai/practice/6293

// A : 1 0000 0000
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int min_val;
    int input;
    int cnt = 0;
    vector<int> stone(N);
    vector<int> dp_mem;
    dp_mem.assign(N, 1);

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        stone[i] = input;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (stone[i] > stone[j])
            {
                dp_mem[i] = max(dp_mem[j] + 1, dp_mem[i]);
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < N; i++)
    {
        ans = max(dp_mem[i], ans);
    }
    cout << ans;

    return 0;
}