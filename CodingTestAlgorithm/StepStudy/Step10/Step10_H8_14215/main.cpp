#include <bits/stdc++.h>

using namespace std;

int A, B, C;
int sum;
int maxL, temp;
int main()
{
	cin >> A >> B >> C;
	maxL = max(A, max(B, C));
	sum = A + B + C;
	if (sum - maxL > maxL)
	{
		cout << sum;
	}
	else
	{
		sum = sum - maxL;
		cout << sum + sum - 1;
	}
}