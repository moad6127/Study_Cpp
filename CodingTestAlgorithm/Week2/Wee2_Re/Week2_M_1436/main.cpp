#include <bits/stdc++.h>	

using namespace std;

int n;
int main()
{
	cin >> n;
	int nums{};
	int s{};
	string C{ "666" };
	while (true)
	{
		if (n == nums)
		{
			break;
		}
		s++;
		if (to_string(s).find(C) != string::npos)
		{
			nums++;
		}
	}
	cout << s;
}