#include <bits/stdc++.h>	

using namespace std;

int n;
string s;
vector<string> result;

bool Comp(string& a, string& b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}
	return a.size() < b.size();
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		string nums;
		for (auto e : s)
		{
			// 0~ 9까지 체크
			if (e >= '0' && e <= '9')
			{
				nums.push_back(e);
			}
			else
			{
				if (nums.size())
				{
					// 앞에 0제거하기
					while (true)
					{
						if (nums.size() == 1)
						{
							break;
						}
						if (nums[0] == '0')
						{
							nums = nums.substr(1);
						}
						else
						{
							break;
						}
					}
					result.push_back(nums);
					nums.clear();
				}
			}
		}
		if (nums.size())
		{
			while (true)
			{
				if (nums.size() == 1)
				{
					break;
				}
				if (nums[0] == '0')
				{
					nums = nums.substr(1);
				}
				else
				{
					break;
				}
			}
			result.push_back(nums);
		}
	}
	sort(result.begin(), result.end(),Comp);
	for (auto e : result)
	{
		cout << e << '\n';
	}
}