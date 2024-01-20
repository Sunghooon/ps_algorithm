// https://softeer.ai/practice/6294
#include <iostream>
#include <vector>

using namespace std;

int accumulated_sum[1000001] = { 0, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<double> answer(K);

    int score;
    for (int i = 1; i <= N; i++)
    {
        cin >> score;
        accumulated_sum[i] = accumulated_sum[i - 1] + score;
    }

    for (int k = 0; k < K; k++)
    {
        int start, end;
        cin >> start >> end;
        answer[k] = (double)(accumulated_sum[end] - accumulated_sum[start - 1]) / (end - start + 1);
    }
    for (int k = 0; k < K; k++)
    {
        printf("%.2f\n", answer[k]);
    }

    return 0;
}