#include <bits/stdc++.h>

using namespace std;

int T, C;
const vector<int> CList{25, 10, 5, 1};
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> C;
		vector<int> result(4, 0);
		int j{};
		while (C)
		{
			if (C >= CList[j])
			{
				result[j] = C / CList[j];
				C %= CList[j];
			}
			else
			{
				j++;
			}
		}
		for (auto e : result)
		{
			cout << e << " ";
		}
		cout << '\n';
	}

}