#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int start_num = 3;
    for (int i = 1; i < N; i++)
    {
        start_num = 2 * start_num - 1;
    }
    int sum = 0;
    while (start_num != 1)
    {
        sum += 4 * start_num - 4;
        start_num -= 2;
    }
    sum += 1;
    
    cout << sum;
    return 0;
}