// https://softeer.ai/practice/6268

/* 7-segment indexing

        0   0
    1           2
    1           2
    1           2
        3   3
    4           5
    4           5
    4           5
        6   6
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number[11][7] =
{
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0}
};

int compare_two_num(int a, int b)
{
    int cnt = 0;
    for (int i = 0; i < 7; i++)
    {
        if (number[a][i] != number[b][i])
            cnt++;
    }
    return cnt;
}
int compare(queue<int> a, queue<int> b)
{
    int answer = 0;

    int a_num, b_num;
    while (a.empty() != true && b.empty() != true)
    {
        
        if (a.size() > b.size())
        {
            a_num = a.front();
            answer += compare_two_num(a_num, 10); // 10 means 'NULL'
            a.pop();
        }
        else if (a.size() < b.size())
        {
            b_num = b.front();
            answer += compare_two_num(b_num, 10);
            b.pop();
        }
        else
        {
            a_num = a.front();
            b_num = b.front();
            answer += compare_two_num(a_num, b_num);
            a.pop();
            b.pop();
        }

    }
    return answer;
}
int main()
{
    int T;
    cin >> T;

    vector<int> answer(T);
    for (int t = 0; t < T; t++)
    {
        string a, b;
        cin >> a >> b;
        queue<int> A, B;
        for (int i = 0; i < a.size(); i++)
        {
            A.push(a[i] - '0');
        }
        for (int i = 0; i < b.size(); i++)
        {
            B.push(b[i] - '0');
        }

        answer[t] = compare(A, B);

    }

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}