#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> window; // <idx, val>
    vector<int> num_box(N);
    vector<int> answer(N);
    int val;
    for (int i = 0; i < N; i++)
    {
        cin >> val;
        num_box[i] = val;
    }

    for (int i = 0; i < N; i++)
    {
        while (window.empty() == false && window.back().second > num_box[i])
        {
            window.pop_back();
        }
        window.push_back(make_pair(i, num_box[i]));
        if (window.front().first <= i - L)
        {
            window.pop_front();
        }
        answer[i] = window.front().second;
    }

    for (int i = 0; i < N; i++)
    {
        cout << answer[i] << " ";
    }
}