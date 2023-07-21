#include <bits/stdc++.h>

using namespace std;

//내가 푼 풀이

/*
int Check(vector<int>& check)
{
	int sum{};
	for (auto e : check)
	{
		sum += e;
	}
	return sum;
}

void func(vector<int>& key,vector<int>& check, int n, bool& bCheck)
{
	if (bCheck)
	{
		return;
	}
	if (check.size() == 7)
	{
		int sum = Check(check);
		if (sum == 100)
		{
			sort(check.begin(), check.end());
			bCheck = true;
			for (auto e : check)
			{
				cout << e << endl;
			}
			return;
		}
	}

	for (int i = n + 1; i < key.size(); i++)
	{
		check.push_back(key[i]);
		func(key, check, i,bCheck);
		check.pop_back();
	}
}


int main()
{
	vector<int> key;
	vector<int> check;
	bool bCheck{false};
	for (int i = 0; i < 9; i++)
	{
		int a{};
		cin >> a;
		key.push_back(a);
	}

	func(key, check, -1,bCheck);
}*/

// 순열로 푼 방법 do, While로 풀기
/*
int main()
{
	vector<int> key(9,0);
	for (int i = 0; i < 9; i++)
	{
		cin >> key[i];
	}

	sort(key.begin(), key.end());
	do 
	{
		int sum{};
		for (int i = 0; i < 7; i++)
		{
			sum += key[i];
		}
		if (sum == 100)
		{
			break;
		}
	} while (next_permutation(key.begin(), key.end()));

	for (int i = 0; i < 7; i++)
	{
		cout << key[i] << endl;
	}
}
*/

// 조합으로 풀기, 이상한 애들 2개를 찾기
/*
void solve(vector<int>& key, pair<int, int>& out,int sum)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (sum - key[i] - key[j] == 100)
			{
				out = { i,j };
				return;
			}
		}
	}
}

int main()
{
	vector<int> key(9, 0);
	int sum{};
	pair<int,int> out;
	for (int i = 0; i < 9; i++)
	{
		cin >> key[i];
		sum += key[i];
	}
	solve(key, out, sum);
	vector<int> check;

	for (int i = 0; i < 9; i++)
	{
		if (out.first == i || out.second == i)
		{
			continue;
		}
		check.push_back(key[i]);
	}
	sort(check.begin(), check.end());
	for (auto e : check)
	{
		cout << e << endl;
	}
}
*/

// 재귀함수로 permutation만들어서 해보기

int a[9];
int n = 9, r = 7;


void solve()
{
	int sum{};
	for (int i = 0; i < r; i++)
	{
		sum += a[i];
	}
	if (sum == 100)
	{
		sort(a, a + 7);
		for (int i = 0; i < r; i++)
		{
			cout << a[i] << endl;
		}
		exit(0);
	}
}
void makepermutation(int n, int r, int depth)
{
	if (depth == r)
	{
		solve();
		return;
	}

	for (int i = depth; i < n; i++)
	{
		swap(a[i], a[depth]);
		makepermutation(n, r, depth + 1);
		swap(a[i], a[depth]);
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
	}
	makepermutation(n, r, 0);
}

