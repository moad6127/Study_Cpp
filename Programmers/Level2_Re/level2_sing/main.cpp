#include <string>
#include <vector>

using namespace std;

string NONSH{ "EB" };

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

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int time{};
    for (auto e : musicinfos)
    {
        vector<string> info = InfoSplit(e);
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

        size_t itr = nowsing.find(m);

        if (itr == string::npos);
        {
            continue;
        }
        if (nowsing[itr + m.size()] != '#')
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
    solution("ABCDEFG", { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" });
}