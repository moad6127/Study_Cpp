#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> list;
    unordered_map<int, string>list2;
    for (int i = 0; i < players.size(); i++)
    {
        list[players[i]] = i + 1;
        list2[i + 1] = players[i];
    }
    for (auto e : callings)
    {
        list[e]--;
        string tempStr = list2[list[e]];
        list[tempStr]++;
        int temp = list[e];
        list2[temp] = e;
        list2[temp + 1] = tempStr;
    }
    for (int i = 0; i < players.size(); i++)
    {
        answer.push_back(list2[i + 1]);
    }
    return answer;
}