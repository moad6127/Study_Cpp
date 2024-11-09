#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int TimeToInt(string s)
{
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3));

    return h * 60 + m;
}

bool Comp(vector<string>& a, vector<string>& b)
{
    return a[1] < b[1];
}


vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> st;

    sort(plans.begin(), plans.end(), Comp);
    int prev{-1};
    //이전 시간과 현재 시간을 비교해서 차이가
    //필요 시간을 넘어가면 제거 아니면 차이를 필요 시간에서 뺀다
    for (auto plan : plans)
    {
        int time = TimeToInt(plan[1]);
        if (prev == -1)
        {
            prev = time;
            st.push({ plan[0],stoi(plan[2]) });
            continue;
        }
        int checkTime = time - prev;
        while (st.size())
        {
            if (checkTime <= 0)
            {
                break;
            }
            pair<string, int> now = st.top();
            st.pop();
            if (checkTime >now.second)
            {
                checkTime -= now.second;
                answer.push_back(now.first);
            }
            else if (checkTime == now.second)
            {
                answer.push_back(now.first);
                checkTime = 0;
            }
            else
            {
                now.second -= checkTime;
                checkTime = 0;
                st.push({ now.first,now.second });
            }
        }
        prev = time;
        st.push({ plan[0],stoi(plan[2]) });
    }
    while (st.size())
    {
        pair<string, int> now = st.top();
        st.pop();
        answer.push_back(now.first);
    }
    return answer;
}

int main()
{
    vector<vector<string>> plans {{"science", "12:40", "50"},
        { "music", "12:20", "40" },
        { "history", "14:00", "30" },
        { "computer", "12:30", "100" }};
    solution(plans);
}