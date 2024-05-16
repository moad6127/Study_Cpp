#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<int> NUMS{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string MaxString = "999999999999999999999999999999999999999999999999999";
string minDP[104];

string minStr(string a, string b)
{
	if (a.size() == b.size())
	{
		return a < b ? a : b;
	}
	if (a.size() < b.size())
	{
		return a;
	}
	else
	{
		return b;
	}
}
string MaxFunc(int nums)
{
	string result;
	if (nums & 1)
	{
		result += '7';
		nums -= 3;
	}
	while (nums)
	{
		result += '1';
		nums -= 2;
	}
	return result;
}
string MinFunc(int nums)
{
	if (nums == 0)
	{
		return "";
	}
	if (minDP[nums] != MaxString)
	{
		return minDP[nums];
	}
	for (int i = 0; i < NUMS.size(); i++)
	{
		if (nums == N && i == 0)
		{
			continue;
		}
		if (nums - NUMS[i] < 0)
		{
			continue;
		}

		if (nums >= NUMS[i])
		{
			minDP[nums] = minStr(minDP[nums], to_string(i) + MinFunc(nums - NUMS[i]));
		}
	}
	return minDP[nums];
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		fill(minDP, minDP + 104, MaxString);
		cout << MinFunc(N) << " " << MaxFunc(N)<<'\n';
	}
}