// https://softeer.ai/practice/6295
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int T;
    cin >> T;

    vector<int> answer(T); // dynamically assign 
    int a, b; // 1 <= a,b <= 9
    for(int t = 0; t < T; t++)
    {
        cin >> a >> b;
        answer[t] = a+b;
    }
    for(int t = 0; t < T; t++)
    {
         cout << "Case #" << t+1 << ": " << answer[t] << endl;   
    }
    
   return 0;
}