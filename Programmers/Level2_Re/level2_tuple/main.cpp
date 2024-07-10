#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

bool Comp(vector<int>& a, vector<int>& b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    s.pop_back();
    s = s.substr(1);
    vector<vector<int>> temp;
    vector<int> v;
    string nums;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{')
        {
            continue;
        }
        else if (s[i] == '}')
        {
            if (!nums.empty())
            {
                v.push_back(stoi(nums));
                nums.clear();
            }
            temp.push_back(v);
            v.clear();
            continue;
        }
        else if (s[i] == ',')
        {
             if (s[i - 1] != '}')
             {
                v.push_back(stoi(nums));
                nums.clear();
             }
             continue;
        }
        nums.push_back(s[i]);
    }
    sort(temp.begin(), temp.end(), Comp);
    unordered_set<int> uset;
    for (auto e : temp)
    {
        for (auto k : e)
        {
            if (uset.insert(k).second)
            {
                answer.push_back(k);
            }
        }
    }
    return answer;
}

int main()
{
    solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
}