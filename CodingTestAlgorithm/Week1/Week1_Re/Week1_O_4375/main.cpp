#include <bits/stdc++.h>

using namespace std;

int n;


int main()
{
	while (cin >> n)
	{
		long long nums{ 1 };
		int cnt{ 1 };
		while (true)
		{
			if (nums % n == 0)
			{
				cout << cnt << '\n';
				break;
			}
			nums = nums * 10 + 1;
			nums %= n;
			cnt++;
		}

	}
}