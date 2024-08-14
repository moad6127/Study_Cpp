#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> table;
void dfs(string order, vector<int> visited, int here, string input)
{
    if (here >= order.size())
    {
        return;
    }
    for (int i = here; i < order.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            input += order[i];
            if (input.size() >= 2)
            {
                table[input]++;
            }
            dfs(order, visited, i + 1, input);
            input.pop_back();
            visited[i] = 0;
        }
    }
}
bool comp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++)
    {
        vector<int> visited(orders.size() + 1,0);
        sort(orders[i].begin(), orders[i].end());
        dfs(orders[i], visited, 0, "");
    }
    vector<pair<string, int>> vt(table.begin(),table.end());
    sort(vt.begin(), vt.end(), comp);

    for (int i = 0; i < course.size(); i++)
    {
        int max = 2;
        for (auto e : vt)
        {
            if (e.first.size() != course[i])
            {
                continue;
            }
            if (max < e.second )
            {
                max = e.second;
                answer.push_back(e.first);
            }
            else if (max == e.second)
            {
                answer.push_back(e.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    solution({ "XYZ", "XWY", "WXA" }, { 2, 3, 4 });
}