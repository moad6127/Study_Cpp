#include <string>
#include <vector>

using namespace std;

int ToTime(string t)
{
    int h = stoi(t.substr(0, 2));
    int m = stoi(t.substr(3));

    return 60 * h + m;
}

vector<string> InfoSplit(string Ininfo)
{
    vector<string> info;
    string temp;
    for (auto k : Ininfo)
    {
        if (k == ',')
        {
            info.push_back(temp);
            temp.clear();
            continue;
        }
        temp.push_back(k);
    }
    info.push_back(temp);

    return info;
}
int singLen(string s)
{
    int result = s.size();
    int shCnt{};
    for (auto e : s)
    {
        if (e == '#')
        {
            shCnt++;
        }
    }
    return result - shCnt;
}
string changeS(string s)
{
    string result;
    for (auto e : s)
    {
        if (e == '#')
        {
            char pr = result.back();
            result.pop_back();
            result.push_back(tolower(pr));
            continue;
        }
        result.push_back(e);
    }
    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int time{};
    string reM = changeS(m);
    for (auto e : musicinfos)
    {
        vector<string> info = InfoSplit(e);
        info[3] = changeS(info[3]);
        int startTime = ToTime(info[0]);
        int endTime = ToTime(info[1]);
        int infoLen = endTime - startTime;
        int SLen = singLen(info[3]);
        string nowsing{ info[3] };
        int nowSLen{ SLen };
        while (true)
        {
            if (nowSLen == infoLen)
            {
                break;
            }
            if (nowSLen < infoLen)
            {
                nowsing += info[3];
                nowSLen += SLen;
            }
            else
            {
                if (nowsing.back() == '#')
                {
                    nowsing.pop_back();
                }
                nowsing.pop_back();
                nowSLen -= 1;
            }
        }

        size_t itr = nowsing.find(reM);
        if (itr != string::npos)
        {
            if (time < infoLen)
            {
                answer = info[2];
                time = infoLen;
            }
        }
    }
    return answer;
}
int main()
{
    solution("CC#BCC#BCC#BCC#B", { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" });
}