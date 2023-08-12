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

반복문
첫번째 팀의 스코어 두번재 팀의 스코어를 저장하기
이전 시간을 저장할 변수도 선언한다
반복문으로 어느팀이 넣었는지와 시간을 입력받는다
시간을 초로 변경한후 점수가 더 높은 팀에 이전시간과 현재 시간의 차이를 더해준다
반복문이 끝나면
이전값과 최대값의 시간차이를 점수가 더높은팀에 더해준다
초를 다시 출력할 형태로 만들어준뒤 출력한다

*/