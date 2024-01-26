#include <iostream>
#include <vector>

using namespace std;

int number_arr[1000001];


int find_function(int a)
{
	if (number_arr[a] == a)
		return a;
	else
	{
		return number_arr[a] = find_function(number_arr[a]);
	}
}
void union_function(int a, int b)
{
	a = find_function(a);
	b = find_function(b);

	if (a != b)
	{
		if (a < b)
		{
			number_arr[b] = a;
		}
		else
		{
			number_arr[a] = b;
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> answer;

	for (int i = 1; i <= n; i++)
	{
		number_arr[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int mode, a, b;
		cin >> mode >> a >> b;

		if (mode == 0) // union
		{
			union_function(a, b);
		}
		else // find
		{
			if (find_function(a) == find_function(b)) 
				answer.push_back("YES");
			else
				answer.push_back("NO");
		}
	}
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}

	return 0;
}