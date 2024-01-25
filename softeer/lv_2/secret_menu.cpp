//https://softeer.ai/practice/6269
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int M, N, K;
    cin >> M >> N >> K;

    vector<int> secret_list(M);
    vector<int> user_command(N);

    for (int i = 0; i < M; i++)
    {
        int t;
        cin >> t;
        secret_list[i] = t;
    }
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        user_command[i] = t;
    }

    int mark = 0;
    int cnt = 0;
    bool success = false;
    for (int i = 0; i < N; i++)
    {
        if (user_command[i] == secret_list[0])
        {
            cnt = 1;
            for (int j = 1; j < M; j++)
            {
                if (i + j < N)
                {
                    if (user_command[i + j] == secret_list[j])
                    {
                        cnt++;
                    }
                }
            }
            if (cnt == M)
            {
                success = true;
            }
        }
    }

    if (success == true) cout << "secret";
    else cout << "normal";


    return 0;
}