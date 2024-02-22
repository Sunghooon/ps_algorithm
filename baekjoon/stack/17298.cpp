#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> ans(N);
    for(int i = 0; i < N; i++)
    {
        int _in;
        cin >> _in;
        A[i] = _in;
    }

    stack<int> s;
    for(int i = N-1; i >= 0; i--)
    {
        while(s.empty() == false && s.top() <= A[i])
        {
            s.pop();
        }

        if(s.empty() == true) ans[i] = -1;
        else ans[i] = s.top();

        s.push(A[i]);
    }

    for(int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}