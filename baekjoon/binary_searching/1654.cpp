#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cutting_cnt(vector<int>& line, int given_length)
{
    int answer = 0;
    for (int i = 0; i < line.size(); i++)
    {
        answer += line[i] / given_length;
    }
    return answer;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> line(N);
    int tmp_max = -1;
    for (int i = 0; i < N; i++)
    {
        int _in;
        cin >> _in;
        line[i] = _in;
        tmp_max = max(tmp_max, _in);
    }
    long long int left = 1;
    long long int right = tmp_max;
    long long int mid = (left + right) / 2;
    int answer = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        int curr_cnt = cutting_cnt(line, mid);
        if (curr_cnt >= K)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << answer;

    return 0;
}