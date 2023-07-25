#include <bits/stdc++.h>

using namespace std;



int main()
{
	int num{};
	while (!cin.eof() && cin >> num)
	{
		long long cnt = 1, result = 1;
		while (true)
		{
			if (cnt % num == 0)
			{
				cout << result << '\n';
				break;
			}
			else
			{
				cnt = (cnt * 10) + 1;
				cnt %= num;
				result++;
			}
		}
	}
}