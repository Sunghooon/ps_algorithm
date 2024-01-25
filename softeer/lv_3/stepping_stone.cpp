// https://softeer.ai/practice/6293

// A : 1 0000 0000
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    int max_val = -1;
    int input;
    int cnt = 0;
    for(int i = 0 ; i < N; i++)
    {
        cin >> input;
        if(input > max_val)
        {
            cnt++;
            max_val = input;
        }
            
    }

    cout << cnt;

    return 0;
}