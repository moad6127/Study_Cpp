#include <string>
#include <vector>

using namespace std;
int TimeCheck(int time)
{
    int h = time / 100;
    int m = time % 100;

    m += 10;
    if (m / 60)
    {
        h++;
        m -= 60;
    }
    return h * 100 + m;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = schedules.size();
    startday--;
    //0번 사람부터 체크
    for (int p = 0; p < timelogs.size();p++)
    {
        int maxTime = TimeCheck(schedules[p]);

        //일주일동안 순회
        for (int i = 0; i < 7;i++)
        {
            //주말 제외
            if (((startday + i) % 7) >= 5)
            {
                continue;
            }
            if (timelogs[p][i] > maxTime)
            {
                answer -= 1;
                break;
            }
        }
    }

    return answer;
}
int main()
{
    vector<int> schedules{ 700, 800, 1100 };
    vector<vector<int>> timelogs
    { {710, 2359, 1050, 700, 650, 631, 659},
        {800, 801, 805, 800, 759, 810, 809},
        {105, 1001, 1002, 600, 1059, 1001, 1100} };

    int startday{5};
    solution(schedules, timelogs, startday);
}