#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> list;
    for (int i = 0; i < s.size(); i++)
    {
        if (list.find(s[i]) != list.end())
        {
            answer.push_back(i - list[s[i]]);
        }
        else
        {
            answer.push_back(-1);
        }
        list[s[i]] = i;
    }
    return answer;
}