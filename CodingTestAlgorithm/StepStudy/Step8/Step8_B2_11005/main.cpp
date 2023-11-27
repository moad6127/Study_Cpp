#include <bits/stdc++.h>

using namespace std;

int N, B;
string result;
int main()
{
	cin >> N >> B;

	while (N)
	{
		int mod = N % B;
		N /= B;
		char temp{};
		if (mod >= 10)
		{
			temp = (mod - 10) + 'A';
		}
		else
		{
			temp = mod + '0';
		}
		result += temp;
	}
	reverse(result.begin(), result.end());
	cout << result;
}