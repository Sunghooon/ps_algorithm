#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int M, N;
    int number_arr[1000001];
    cin >> M >> N;

    for (int i = M; i <= N; i++)
    {
        number_arr[i] = i;
    }
    number_arr[1] = 0;

    for (int i = 1; i <= sqrt(N); i++)
    {
        if (i == 1) continue;
        
        int multiply = 2;
        while (i * multiply <= N)
        {
            number_arr[i * multiply] = 0;
            multiply++;
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (number_arr[i] != 0) cout << i << "\n";
    }

    return 0;
}