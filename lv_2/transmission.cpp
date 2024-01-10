//https://softeer.ai/practice/6283
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int input;
    vector<int> trans_history(8);

    cin >> input;
    trans_history[0] = input;
    int n_asc = 0, n_desc = 0;
    for(int i = 1; i < 8; i++)
    {
        cin >> input;
        trans_history[i] = input;
        if(trans_history[i] > trans_history[i-1])
        {
            n_asc++;
        }
        else if(trans_history[i] < trans_history[i-1])
        {
            n_desc++;
        }
    }

    if(n_desc == 7)
        cout << "descending";
    else if(n_asc == 7)
        cout << "ascending";
    else
        cout << "mixed";

    return 0;
}