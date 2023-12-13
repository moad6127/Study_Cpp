#include <bits/stdc++.h>

using namespace std;

int A, B, C,sum;
const int SUM = 180;
int main()
{
	cin >> A >> B >> C;
	if (A == B && B == C && A == 60)
	{
		cout << "Equilateral";
	}
	else if (A + B + C == SUM)
	{
		if (A != B && B != C && A != C)
		{
			cout << "Scalene";
		}
		else
		{
			cout << "Isosceles";
		}
	}
	else
	{
		cout << "Error";
	}
}