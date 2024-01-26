#include <iostream>

using namespace std;

int map[201][201] = {0,};
int parent[201];

int main()
{
    int N;
    cin >> N;
    int M;
    cin >> M;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int a;
            cin >> a;
            map[i][j] = a;
        }
    }

    ///
    
    ///


    return 0;
}