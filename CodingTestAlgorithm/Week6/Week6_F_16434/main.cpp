#include <bits/stdc++.h>

using namespace std;

long long N, Hatk, t, a, h, damage,H,mx;


int main()
{
	cin >> N >> Hatk;

	for (int i = 0; i < N; i++)
	{
		cin >> t >> a >> h;
		if (t == 1)
		{
			damage = a * (ceil((double)h / Hatk) - 1);
			if (H < damage)
			{
				mx += damage - H;
				H = 0;
			}
			else
			{
				H -= damage;
			}
		}
		else
		{
			Hatk += a;
			H = min(H + h, mx);
		}
	}
	cout << mx + 1;
}