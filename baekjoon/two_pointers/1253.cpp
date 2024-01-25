#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> num_box(N);

    int val;
    for (int i = 0; i < N; i++)
    {
        cin >> val;
        num_box[i] = val;
    }
    sort(num_box.begin(), num_box.end());

    int ptr1, ptr2;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int std_val = num_box[i];
        ptr1 = 0; ptr2 = N - 1;
        while (ptr1 < ptr2)
        {
            if (num_box[ptr1] + num_box[ptr2] > std_val)
            {
                ptr2--;
            }
            else if (num_box[ptr1] + num_box[ptr2] < std_val)
            {
                ptr1++;
            }
            else
            {
                if (ptr1 != i && ptr2 != i)
                {
                    cnt++;
                    break;
                }
                else if (ptr1 == i)
                {
                    ptr1++;
                }
                else if (ptr2 == i)
                {
                    ptr2--;
                }
             }
        }
    }
    cout << cnt;

    return 0;
}