#include <bits/stdc++.h>

using namespace std;
string A, B;

string AddFunc(string a, string b)
{
	int sum{};
	string result;
	while (a.size() || b.size() || sum)
	{
		if (a.size())
		{
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b.size())
		{
			sum += b.back() - '0';
			b.pop_back();
		}

		result += (sum % 10) + '0';
		sum /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}
int main()
{
	cin >> A >> B;
	cout<<AddFunc(A, B)<<'\n';
}