#include <iostream>
#include <string>

using namespace std;

int main()
{
	string _in;
	getline(cin, _in);

	int length = 1;
	for (int i = 0; i < _in.size(); i++)
	{
		if (_in[i] == ' ')
		{
			length++;
		}
	}
	if (_in[0] == ' ')
	{
		length--;
	}
	if (_in[_in.size() - 1] == ' ')
	{
		length--;
	}
	cout << length;

	return 0;
}