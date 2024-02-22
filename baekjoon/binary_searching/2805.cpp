#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int N, M;
	cin >> N >> M;
	
	vector<int> tree_height(N);

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		tree_height[i] = tmp;
	}
	
	sort(tree_height.begin(), tree_height.end());

	int begin_idx = 0;
	int end_idx = tree_height[N - 1];
	int mid_idx = (begin_idx + end_idx) / 2;
	int max_height = -1;
	

	while (begin_idx <= end_idx)
	{
		mid_idx = (begin_idx + end_idx) / 2;
		long long int received_tree = 0;
		for (int i = 0; i < tree_height.size(); i++)
		{
			if (tree_height[i] > mid_idx)
			{
				received_tree += tree_height[i] - mid_idx;
			}
		}

		if (received_tree >= M)
		{
			begin_idx = mid_idx + 1;
			if (mid_idx > max_height)
			{
				max_height = mid_idx;
			}
		}
		else
		{
			end_idx = mid_idx - 1;
		}
	}

	cout << max_height;
	return 0;
}