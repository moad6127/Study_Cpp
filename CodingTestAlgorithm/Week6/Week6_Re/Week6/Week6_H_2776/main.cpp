#include <bits/stdc++.h>

using namespace std;

int t, n, m, temp;
int FindNums(vector<int>& che, int target)
{
	int low = 0, high = che.size() - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (che[mid] > temp)
		{
			high = mid - 1;
		}
		else if (che[mid] < temp)
		{
			low = mid + 1;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> t;
	while (t--)
	{
		vector<int> che;
		cin >> n;
		for (int i = 0; i < n;i++)
		{
			cin >> temp;
			che.push_back(temp);
		}
		sort(che.begin(), che.end());
		cin >> m;
		for (int i = 0;i < m;i++)
		{
			cin >> temp;
			cout << FindNums(che, temp) << '\n';
		}
	}
}