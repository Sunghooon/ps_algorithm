#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> num_box(N);

    int val;
    for(int i = 0; i < N; i++)
    {
        cin >> val;
        num_box[i] = val;
    }

    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0; j < N - 1 - i; j++)
        {
            if(num_box[j] > num_box[j+1])
            {
                int tmp = num_box[j];
                num_box[j] = num_box[j+1];
                num_box[j+1] = tmp;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout << num_box[i] << endl;
    }
    return 0;
}