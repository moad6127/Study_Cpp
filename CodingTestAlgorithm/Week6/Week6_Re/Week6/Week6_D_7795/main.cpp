#include <bits/stdc++.h>

using namespace std;


int t, n, m;
int main()
{
	cin >> t;
	while (t--)
	{
		int result{};
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);
		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m;i++)
		{
			cin >> b[i];
		}
		sort(b.begin(), b.end());
		sort(a.begin(), a.end());
		for (int i = 0;i < n;i++)
		{
			auto pos = lower_bound(b.begin(), b.end(), a[i]);
			result += (int)(pos - b.begin());
		}
		cout << result << '\n';
	}
}

//int t, A, B;
//int a[20004], b[20004];
//
//int Check(int a)
//{
//	int low = 0;
//	int hi = B - 1;
//	int mid{};
//	while (low <= hi)
//	{
//		mid = (low + hi) / 2;
//		if (b[mid] >= a)
//		{
//			hi = mid - 1;
//		}
//		else 
//		{
//			low = mid + 1;
//		}
//	}
//	if (low > hi)
//	{
//		return low;
//	}
//	else
//	{
//		return mid;
//	}
//
//}
//int main()
//{
//	cin >> t;
//	for (int test = 0 ;test<t;test++)
//	{
//		memset(a, 0, sizeof(a));
//		memset(b, 0, sizeof(b));
//		cin >> A >> B;
//		for (int i = 0; i < A;i++)
//		{
//			cin >> a[i];
//		}
//		for (int i = 0; i < B;i++)
//		{
//			cin >> b[i];
//		}
//		sort(b, b + B);
//		int result{};
//		for (int i = 0; i < A;i++)
//		{
//			result += Check(a[i]);
//		}
//		cout << result << '\n';
//	}
//}