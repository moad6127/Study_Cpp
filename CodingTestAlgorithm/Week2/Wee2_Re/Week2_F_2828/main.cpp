#include <bits/stdc++.h>

using namespace std;

int n, m, J;
int a;
int le, ri;
int result;
int main()
{
	cin >> n >> m >> J;
	le = 1;
	ri = m + 1;
	for (int i = 0; i < J; i++)
	{
		cin >> a;
		if (a < le)
		{
			result += (le - a);
			le = a;
			ri = le + m;
		}
		else if (a >= ri)
		{
			result += ((a - ri) +  1);
			ri = a + 1;
			if(ri > n + 1)
			{
				ri = n;
			}
			le = ri - m;
		}
	}
	cout << result;

}