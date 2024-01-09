// https://softeer.ai/practice/6284
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int K, P, N;
    cin >> K >> P >> N;

    long long int ans = K;
    long long int div = 1000000007;
    for (int n = 0; n < N; n++)
    {
        ans = (ans * P) % div;
    }
    ans = ans % div;
    cout << ans;
    return 0;
}