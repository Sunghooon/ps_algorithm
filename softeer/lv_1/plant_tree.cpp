#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> ground(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ground[i];
    }
    sort(ground.begin(), ground.end());
    if(ground[0] * ground[1] > ground[n-1] * ground[n-2])
    {
        cout << ground[0]*ground[1];
    }
    else
    {
        cout << ground[n-1]*ground[n-2];
    }

    return 0;
}