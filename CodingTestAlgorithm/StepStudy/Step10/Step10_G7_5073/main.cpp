#include <bits/stdc++.h>

using namespace std;

int A, B, C;
int maxL;
int sum;
int main()
{
	while (true)
	{
		cin >> A >> B >> C;
		if (A == 0 && B == 0 && C == 0)
		{
			break;
		}

		maxL = max(A, max(B, C));
		sum = A + B + C;
		if (sum - maxL <= maxL)
		{
			cout << "Invalid" << '\n';
			continue;
		}
		if (A == B && B == C && C == A)
		{
			cout << "Equilateral" << '\n';
		}
		else if (A != B && B != C && C != A)
		{
			cout << "Scalene" << '\n';
		}
		else
		{
			cout << "Isosceles" << '\n';
		}
	}


}