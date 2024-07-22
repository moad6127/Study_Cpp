#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

const string ENT{ "님이 들어왔습니다." };
const string LEV{ "님이 나갔습니다." };

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<bool, string>> ve;
    unordered_map<string, string> Namelist;
    for (auto e : record)
    {
        stringstream ss(e);
        string fir;
        string id;
        string name;
        ss >> fir >> id >> name;
        if (fir == "Enter")
        {
            Namelist[id] = name;
            ve.push_back({ true,id });
        }
        else if (fir == "Leave")
        {
            ve.push_back({ false,id });
        }
        else
        {
            Namelist[id] = name;
        }
    }
    for (auto e : ve)
    {
        string result;
        result += Namelist[e.second];
        if (e.first)
        {
            result += ENT;
        }
        else
        {
            result += LEV;
        }
        answer.push_back(result);
    }
    return answer;
}