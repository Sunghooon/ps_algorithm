#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int accumulated[100001] = {0,}; // value >= 10^8, 1 0000 0000
    int val;
    for(int i = 1; i <= N; i++)
    {
        cin >> val;
        accumulated[i] = accumulated[i-1] + val;
    }
    
    int begin, end;
    for(int m = 0; m < M; m++)
    {
        cin >> begin >> end;
        cout << accumulated[end] - accumulated[begin-1] << "\n";
        // "\n" is faster than "std::endl"
    }
    return 0;
}