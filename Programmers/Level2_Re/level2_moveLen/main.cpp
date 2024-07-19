#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map<char, pair<int, int>> DIR{{'U', { 1,0 } }, { 'D',{-1,0} }, { 'R',{0,1} }, { 'L',{0,-1} }};

int solution(string dirs) {
    int answer = 0;
    unordered_set<string> check;
    pair<int, int> now{5, 5};
    for (auto e : dirs)
    {
        pair<int, int> next = DIR[e];
        int ny = now.first + next.first;
        int nx = now.second + next.second;
        if (ny > 10 || ny < 0 || nx > 10 || nx < 0)
        {
            continue;
        }
        string nowToNe;
        nowToNe.push_back(now.first + '0');
        nowToNe.push_back(now.second + '0');
        nowToNe.push_back(ny + '0');
        nowToNe.push_back(nx + '0');
        string neToNow;
        neToNow.push_back(ny + '0');
        neToNow.push_back(nx + '0');
        neToNow.push_back(now.first + '0');
        neToNow.push_back(now.second + '0');
        check.insert(nowToNe);
        check.insert(neToNow);
        now = { ny,nx };
    }
    answer = check.size() / 2;
    return answer;
}
int main()
{
    solution("LULLLLLLU");
}