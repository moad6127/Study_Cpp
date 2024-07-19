#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer{};
    unordered_map<char, int> list;
    for (auto e : skill)
    {
        list[e]++;
    }
    for (auto e : skill_trees)
    {
        string temp;
        for (auto k : e)
        {
            if (list[k])
            {
                temp.push_back(k);
            }
        }
        string check = skill.substr(0,temp.size());
        if (temp == check)
        {
            answer++;
        }
    }
    return answer;
}
int main()
{
    solution("CBD",{"BACDE", "CBADF", "AECB", "BDA"});
}