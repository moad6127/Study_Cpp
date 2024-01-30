#include <bits/stdc++.h>

using namespace std;


//
//long long N, Hatk, t, a, h, damage,H,mx;
//
//
//int main()
//{
//	cin >> N >> Hatk;
//
//	for (int i = 0; i < N; i++)
//	{
//		cin >> t >> a >> h;
//		if (t == 1)
//		{
//			damage = a * (ceil((double)h / Hatk) - 1);
//			if (H < damage)
//			{
//				mx += damage - H;
//				H = 0;
//			}
//			else
//			{
//				H -= damage;
//			}
//		}
//		else
//		{
//			Hatk += a;
//			H = min(H + h, mx);
//		}
//	}
//	cout << mx + 1;
//}


long long n, attack, t[13005], a[13005], h[13005], lo, hi, result;

bool check(long long mid)
{
	long long mxHP = mid;
	long long init_attack = attack;
	for (int i = 0; i < n; i++) {
		if (t[i] == 2) {
			mid = min(mxHP, mid + h[i]);
			init_attack += a[i];
		}
		else {
			long long cnt = h[i] / init_attack + (h[i] % init_attack ? 1 : 0);
			mid -= (cnt - 1) * a[i];
		}
		if (mid <= 0) return false;
	}
	return true;
}

int main()
{
	cin >> n >> attack;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> a[i] >> h[i];
	}
	lo = 1, hi = 1e18 + 4;
	while (lo <= hi) {
		long long mid = (lo + hi) / 2;
		if (check(mid)) {
			hi = mid - 1;
			result = mid;
		}
		else lo = mid + 1;
	}
	cout << result;
}