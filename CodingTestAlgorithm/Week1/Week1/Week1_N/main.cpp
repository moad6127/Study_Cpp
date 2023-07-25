#include <bits/stdc++.h>

using namespace std;

long long A, B, C;
long long Func(long long A, long long B)
{
	if (B == 1)
	{
		return A % C;
	}

	long long result = Func(A, B / 2);
	result = (result * result) % C;
	if (B % 2)
	{
		result = (result * A) % C;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> A >> B >> C;
	cout<<Func(A, B);
}