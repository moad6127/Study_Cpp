#include <bits/stdc++.h>

using namespace std;

long long TC, num;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		int result{};
		cin >> num;
		long long checkNum{ 5 };
		while (true)
		{
			if (num < checkNum)
			{
				break;
			}
			result += (num / checkNum);
			checkNum *= 5;
		}
		cout << result<<'\n';
	}
}