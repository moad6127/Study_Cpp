#include <bits/stdc++.h>

using namespace std;

int A, B, C;
long long result;
long long Func(long long a, long long b)
{
	if (b == 1)
	{
		return a % C;
	}
	long long res{ 1 };
	res = Func(a, b / 2);
	res = (res * res) % C;
	if (b % 2)
	{
		res = (res * a) % C;
	}
	return res % C;

}
int main()
{
	cin >> A >> B >> C;
	result = Func(A, B);
	cout << result;
}