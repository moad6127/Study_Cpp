#include <bits/stdc++.h>


using namespace std;

int N;
string s;
vector<int> nums;
vector<char>oper_str;
int result = -100000000;
int oper(char a, int b, int c)
{
	if (a == '+')
	{
		return b + c;
	}
	if (a == '-')
	{
		return b - c;
	}
	if (a == '*')
	{
		return b * c;
	}
}
void Func(int here, int _num)
{
	if (here == nums.size() - 1)
	{
		result = max(result, _num);
		return;
	}
	Func(here + 1, oper(oper_str[here], _num, nums[here + 1]));

	if (here + 2 <= nums.size() - 1)
	{
		int temp = oper(oper_str[here + 1], nums[here + 1], nums[here + 2]);
		Func(here + 2, oper(oper_str[here], _num, temp));
	}
}
int main()
{
	cin >> N;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (i % 2 == 0)
		{
			nums.push_back(s[i] - '0');
		}
		else
		{
			oper_str.push_back(s[i]);
		}
	}
	Func(0, nums[0]);
	cout<<result;

}