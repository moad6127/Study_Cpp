#include <bits/stdc++.h>

using namespace std;

int solution(string s)
{
	int result = s.size();
	int n = s.size();
	for (int cnt = 1; cnt <= n / 2; cnt++)
	{
		string comp{};
		string prev = s.substr(0, cnt);
		int count{ 1 };
		for (int j = cnt; j < n; j += cnt)
		{
			string curr = s.substr(j, cnt);
			if (prev == curr)
			{
				count++;
			}
			else
			{
				if (count > 1)
				{
					comp += to_string(count);
				}
				comp += prev;
				prev = curr;
				count = 1;
			}
		}
		if (count > 1)
		{
			comp += to_string(count);
		}
		comp += prev;
		result = min(result, (int)comp.size());
	}
	return result;
}