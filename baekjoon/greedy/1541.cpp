#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string input, char delimeter)
{
    vector<string> result;
    stringstream str_stream(input);
    string tmp;

    while (getline(str_stream, tmp, delimeter))
    {
        result.push_back(tmp);
    }

    return result;
}

int calc_summation(string input)
{
    int ans = 0;
    vector<string> tmp = split(input, '+');

    for (int i = 0; i < tmp.size(); i++)
    {
        ans += stoi(tmp[i]);
    }

    return ans;
}
int main()
{
    string input;
    cin >> input;

    int answer = 0;
    vector<string> part_input = split(input, '-');
    for (int i = 0; i < part_input.size(); i++)
    {
        int s = calc_summation(part_input[i]);
        if (i == 0)
        {
            answer += s;
        }
        else
        {
            answer -= s;
        }
    }

    cout << answer;

    return 0;
}