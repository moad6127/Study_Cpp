#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Info
{
    string name;
    int startTime;
    int playTime;
};

int TimeToInt(string time)
{
    string h = time.substr(0, 2);
    string m = time.substr(3);

    return stoi(h) * 60 + stoi(m);
}
bool comp(Info& a, Info& b)
{
    return a.startTime < b.startTime;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Info> vi;
    stack<pair<string,int>> st;
    for (auto e : plans)
    {
        Info temp;
        temp.name = e[0];
        temp.startTime = TimeToInt(e[1]);
        temp.playTime = stoi(e[2]);
        vi.push_back(temp);
    }
    sort(vi.begin(), vi.end(), comp);
    Info prv;
    int prvTime{-1};
    for (auto e : vi)
    {
        int nowTime = e.startTime;
        if (prvTime != -1)
        {
            int tempTime = nowTime - prvTime;
            if (tempTime > prv.playTime)
            {
                answer.push_back(prv.name);
                tempTime -= prv.playTime;
                while (st.size())
                {
                    pair<string, int> stTop = st.top();
                    st.pop();
                    tempTime -= stTop.second;
                    if (tempTime >= 0)
                    {
                        answer.push_back(stTop.first);
                    }
                    else
                    {
                        stTop.second = -1 * tempTime;
                        st.push(stTop);
                        break;
                    }

                }
            }
            else  if (tempTime == prv.playTime)
            {
                answer.push_back(prv.name);
            }
            else
            {
                st.push({ prv.name,prv.playTime - tempTime });
            }
        }
        prvTime = nowTime;
        prv = e;
    }
    answer.push_back(prv.name);
    while (st.size())
    {
        answer.push_back(st.top().first);
        st.pop();
    }
    return answer;
}

int main()
{
    vector<vector<string>> v{{"a", "00:00", "20"}, { "b","00:01","20" }, { "c","00:02","20" }, { "d","20:00","30" }};
    solution(v);
}