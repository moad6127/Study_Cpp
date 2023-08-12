#include <bits/stdc++.h>

using namespace std;

int N;

int ToSecond(string input)
{
	int Min{}, Second{}, result{};
	Min = stoi(input.substr(0, 2));
	Second = stoi(input.substr(3));

	result = (Min * 60) + Second;
	return result;
}

string SecondToStirng(int second)
{
	string result{};
	int Min{}, Second{};
	Min = second / 60;
	Second = second % 60;
	string MS = to_string(Min);
	if (MS.size() == 1) 
	{
		MS = "0" + MS;
 	}
	string SS = to_string(Second);
	if (SS.size() == 1)
	{
		SS = "0" + SS;
	}

	result += MS + ":" + SS;
	return result;
}


int main()
{
	int FTime{}, STime{};
	int maxM = ToSecond("48:00");
	int goalTeam{};
	string goalTime{};
	string prev;
	int A{}, B{};
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> goalTeam >> goalTime;
		if (A > B)
		{
			FTime += (ToSecond(goalTime) - ToSecond(prev));
		}
		else if (B > A)
		{
			STime += (ToSecond(goalTime) - ToSecond(prev));
		}
		if (goalTeam == 1)
		{
			A++;
		}
		else
		{
			B++;
		}
		prev = goalTime;
	}
	if (A > B)
	{
		FTime += maxM - ToSecond(prev);
	}
	else if (B> A)
	{
		STime += maxM - ToSecond(prev);
	}
	cout << SecondToStirng(FTime) << '\n';
	cout << SecondToStirng(STime) << '\n';
}


/*

�ݺ���
ù��° ���� ���ھ� �ι��� ���� ���ھ �����ϱ�
���� �ð��� ������ ������ �����Ѵ�
�ݺ������� ������� �־������� �ð��� �Է¹޴´�
�ð��� �ʷ� �������� ������ �� ���� ���� �����ð��� ���� �ð��� ���̸� �����ش�
�ݺ����� ������
�������� �ִ밪�� �ð����̸� ������ ���������� �����ش�
�ʸ� �ٽ� ����� ���·� ������ص� ����Ѵ�

*/