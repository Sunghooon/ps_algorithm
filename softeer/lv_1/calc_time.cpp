// https://softeer.ai/practice/6254
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int ans = 0;
    for(int i = 0; i < 5; i++)
    {
        int start_h, start_m;
        int end_h, end_m;

        scanf("%d:%d %d:%d", &start_h, &start_m, &end_h, &end_m);
        ans += (end_h - start_h)*60 + (end_m - start_m);
    }

    cout << ans;
    return 0;
}
