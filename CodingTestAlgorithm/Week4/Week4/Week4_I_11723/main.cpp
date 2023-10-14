#include <bits/stdc++.h>

using namespace std;


int S;
int N;
string str;
int num;
void Add(int num)
{
	S |= (1 << num);
}
void Remove(int num)
{
	S &= ~(1 << num);
}
void Check(int num)
{
	if (S & (1 << num))
	{
		cout << 1 << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}

}
void Toggle(int num)
{
	S ^= (1 << num);
}
void All()
{
	S = (1 << 21) - 1;
}
void Empty()
{
	S = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (str == "add")
		{
			cin >> num;
			Add(num);
		}
		else if (str == "remove")
		{
			cin >> num;
			Remove(num);
		}
		else if (str == "check")
		{
			cin >> num;
			Check(num);
		}
		else if (str == "toggle")
		{
			cin >> num;
			Toggle(num);
		}
		else if (str == "all")
		{
			All();
		}
		else if (str == "empty")
		{
			Empty();
		}
	}
}