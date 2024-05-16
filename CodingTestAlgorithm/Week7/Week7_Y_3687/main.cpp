#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<int> NUMS{6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string MinString = "999999999999999", MaxString;
string MinDP[103];
string MaxDP[103];

bool Comp(string a, string b)
{
	if (a.size() == b.size())
	{
		return a > b;
	}
	return a.size() > b.size();
}
void MaxFunc(int nums, string st)
{
	if (nums == 0)
	{
		if (!Comp(MaxString, st))
		{
			MaxString = st;
		}
	}

	for (int i = 0; i < NUMS.size(); i++)
	{
		if (st.empty() && i == 0)
		{
			continue;
		}
		if (nums >= NUMS[i])
		{
			MaxFunc(nums - NUMS[i], st + to_string(i));
		}
	}
}
void MinFunc(int nums, string st)
{
	if (nums == 0)
	{
		if (Comp(MinString, st))
		{
			MinString = st;
		}
		return;
	}

	for (int i = 0; i < NUMS.size(); i++)
	{
		if (st.empty() && i == 0)
		{
			continue;
		}
		if (nums >= NUMS[i])
		{
			MinFunc(nums - NUMS[i], st + to_string(i));
		}
	}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		MinString = "999999999999999";
		MaxString.clear();
		MaxFunc(N, "");
		MinFunc(N, "");
		cout << MinString << " " << MaxString<<'\n';
	}
}