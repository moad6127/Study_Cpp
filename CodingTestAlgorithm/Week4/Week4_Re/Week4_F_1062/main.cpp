#include <bits/stdc++.h>	

using namespace std;

int n, k;
string s;
int words[52];
int cnt(int mask)
{
	int cnt = 0;
	for (int word : words)
	{
		if (word && (word & mask) == word)
		{
			cnt++;
		}
	}
	return cnt;
}

int Func(int index, int k, int mask)
{
	if (k < 0)
	{
		return 0;
	}
	if (index == 26)
	{
		return cnt(mask);
	}
	int ret = Func(index + 1, k - 1, mask | (1 << index));
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a')
	{
		ret = max(ret, Func(index + 1, k, mask));
	}

	return ret;
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (auto str : s)
		{
			words[i] |= (1 << (str - 'a'));
		}
	}
	cout << Func(0, k, 0);
}