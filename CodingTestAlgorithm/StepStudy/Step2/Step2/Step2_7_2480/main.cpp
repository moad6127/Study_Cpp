#include <bits/stdc++.h>

using namespace std;
int A, B, C;
int main()
{
	cin >> A >> B >> C;
	if (A == B && B == C)
	{
		cout << 10000 + (A * 1000);
	}
	else if (A != B && B != C && C != A)
	{
		cout << max(A, max(B, C)) * 100;
	}
	else
	{
		if (A == B || A ==C)
		{
			cout << 1000 + (A * 100);
		}
		else if (B == C)
		{
			cout << 1000 + (B * 100);
		}
	}
}