#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

int TimeToInt(string InTime)
{
    int h = stoi(InTime.substr(0, 2));
    int m = stoi(InTime.substr(3));

    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, pair<int, bool>> list;
    map<string, int> mp;
    for (auto e : records)
    {
        stringstream ss(e);
        string time;
        string nums;
        string stat;
        ss >> time >> nums >> stat;
        int t = TimeToInt(time);
        if (stat == "OUT")
        {
            list[nums].second = false;
            mp[nums] += t - list[nums].first;
            list[nums].first = 0;
        }
        else
        {
            list[nums].second = true;
            list[nums].first = t;
        }
    }
    int maxTime = TimeToInt("23:59");
    for (auto e : list)
    {
        if (e.second.second)
        {
            mp[e.first] += maxTime - e.second.first;
        }
    }
    for (auto e : mp)
    {
        int result{ fees[1] };
        if (e.second > fees[0])
        {
            int mul = (e.second - fees[0]) / fees[2];
            if ((e.second - fees[0]) % fees[2])
            {
                mul++;
            }
            result += mul * fees[3];
        }
        answer.push_back(result);
    }
    return answer;
}
