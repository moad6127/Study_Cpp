#include <bits/stdc++.h>

using namespace std;
string A, B;
string result;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B;

	for (auto e : A)
	{
		result += e;
		if (result.size() >= B.size() && result.substr(result.size() - B.size(), B.size()) == B)
		{
			result.erase(result.end() - B.size(), result.end());
		}
	}

	if (result.size())
	{
		cout << result<<'\n';
	}
	else
	{
		cout << "FRULA" << '\n';
	}
}