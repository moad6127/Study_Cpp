#include <bits/stdc++.h>

using namespace std;
int N, K;
int w[51];

int count(int mask)
{
	int cnt = 0;
	for (int e : w)
	{
		if (e && (e & mask) == e)
		{
			cnt++;
		}
	}
	return cnt;
}

int Func(int index, int K, int mask)
{
	if (K < 0)
	{
		return 0;
	}
	if (index == 26)
	{
		return count(mask);
	}
	int result = Func(index + 1, K - 1, mask | (1 << index));
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a')
	{
		result = max(result, Func(index + 1, K, mask));
	}
	return result;
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (auto e : s)
		{
			w[i] |= (1 << (e - 'a'));
		}
	}
	cout << Func(0, K, 0) << '\n';

}