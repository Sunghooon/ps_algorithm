// https://softeer.ai/practice/6266
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // making format (cout)

using namespace std;


struct MeetingRoom {
	string name;
	vector<pair<int, int>> meeting_list;
	vector<pair<int, int>> available_list;
};
bool compare(MeetingRoom& a, MeetingRoom& b)
{
	return a.name < b.name;
}
void display(MeetingRoom& target)
{
	cout << "Room " << target.name << ":" << endl;
	if (target.available_list.empty() == true)
	{
		cout << "Not available" << endl;
	}
	else
	{
		cout << target.available_list.size() << " available:" << endl;
	}
	
	for (int s = 0; s < target.available_list.size(); s++)
	{
		cout << setw(2) << std::setfill('0') << target.available_list[s].first << "-" << target.available_list[s].second << endl;
	}
}
int main()
{
	int N, M;
	cin >> N >> M;
	vector<MeetingRoom> roomPtr(N);

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		roomPtr[i].name = s;
	}
	for (int i = 0; i < M; i++)
	{
		string r;
		int s, t;
		cin >> r >> s >> t;
		for (int n = 0; n < N; n++)
		{
			if (roomPtr[n].name == r)
			{
				roomPtr[n].meeting_list.push_back(make_pair(s, t));
			}
		}
	}

	for (int n = 0; n < N; n++)
	{
		sort(roomPtr[n].meeting_list.begin(), roomPtr[n].meeting_list.end());
		int timeptr = 9;
		while (timeptr < 18)
		{
			for (int t = 0; t < roomPtr[n].meeting_list.size(); t++)
			{
				int start_t = roomPtr[n].meeting_list.at(t).first;
				int end_t = roomPtr[n].meeting_list.at(t).second;

				if (timeptr < start_t)
				{
					roomPtr[n].available_list.push_back(make_pair(timeptr, start_t));
				}
				timeptr = end_t;
			}
			if (timeptr < 18)
			{
				roomPtr[n].available_list.push_back(make_pair(timeptr, 18));
				timeptr = 18;
			}
		}
	}
	sort(roomPtr.begin(), roomPtr.end(), compare);

	for (int n = 0; n < N; n++)
	{
		display(roomPtr[n]);
		if (n != N - 1)
		{
			cout << "-----" << endl;
		}
	}

	return 0;
}