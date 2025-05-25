#include <bits/stdc++.h>	


using namespace std;

int n, a[1004], len, num;

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> num;
		auto lowerPos = lower_bound(a, a + len, num);
		if (*lowerPos == 0)
		{
			len++;
		}
		*lowerPos = num;
	}
	cout << len << '\n';
}