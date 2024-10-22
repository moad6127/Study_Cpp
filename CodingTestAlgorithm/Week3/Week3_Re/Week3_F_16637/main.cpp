#include <bits/stdc++.h>

using namespace std;
int n;
string a;
vector<int> nums;
vector<char> ops;

int result{-987654321};

int Cal(int a, int b, char op)
{
	if (op == '+')
	{
		return a + b;
	}
	if (op == '-')
	{
		return a - b;
	}
	return a * b;
}

void Func(int here, int _nums)
{
	if (here == nums.size() - 1)
	{
		result = max(result, _nums);
		return;
	}

	Func(here + 1, Cal(_nums, nums[here + 1], ops[here]));
	if (here + 2 <= nums.size() - 1)
	{
		int temp = Cal(nums[here + 1], nums[here + 2], ops[here + 1]);
		Func(here + 2, Cal(_nums, temp, ops[here]));
	}
}
int main()
{
	cin >> n >> a;

	for (int i = 0; i < a.size(); i++)
	{
		if (i & 1)
		{
			ops.push_back(a[i]);
		}
		else
		{
			nums.push_back(a[i] - '0');
		}
	}
	Func(0, nums[0]);
	cout << result;
}