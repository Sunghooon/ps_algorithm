#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> number(N);

    int val;
    for (int i = 0; i < N; i++)
    {
        cin >> val;
        number[i] = val;
    }
    sort(number.begin(), number.end());

    int M;
    cin >> M;
    vector<bool> answer(M);

    for (int i = 0; i < M; i++)
    {
        int val;
        cin >> val;

        // binary search
        int start_idx = 0, end_idx = N - 1;
        int mid_idx;
        while (start_idx <= end_idx)
        {
            mid_idx = (start_idx + end_idx) / 2;
            if (number[mid_idx] > val)
            {
                end_idx = mid_idx - 1;
            }
            else if (number[mid_idx] < val)
            {
                start_idx = mid_idx + 1;
            }
            else // number[mid_idx] == val
            {
                answer[i] = true;
                break;
            }

        }
    }
    for (int i = 0; i < M; i++)
    {
        if (answer[i] == true) cout << 1 << "\n";
        else cout << 0 << "\n";
    }



    return 0;
}