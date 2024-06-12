#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<char, pair<int, int>> NSWE{{'N', { -1, 0 }}, { 'S',{1,0} }, { 'W',{0,-1} }, { 'E',{0,1} }};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> start{-1, -1};
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[0].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                start = { i,j };
                break;
            }
        }
        if (start != pair<int,int>{-1, -1})
        {
            break;
        }
    }
    for (auto e : routes)
    {
        char dir = e[0];
        int cnt = e.back() - '0';
        pair<int, int> temp = start;
        bool bCheck = false;;
        for (int i = 0; i < cnt; i++)
        {
            int ny = temp.first + NSWE[dir].first;
            int nx = temp.second + NSWE[dir].second;
            if (ny < 0 || ny >= park.size() || nx < 0 || nx >= park[0].size() || park[ny][nx] =='X')
            {
                bCheck = true;
                break;
            }
            temp.first = ny;
            temp.second = nx;
        }
        if (!bCheck)
        {
            start = temp;
        }
    }
    return {start.first,start.second};
}
int main()
{
    vector<string> park{"SOO", "OOO", "OOO"};
    vector<string> routes{"E 2", "S 2", "W 1"};
    solution(park, routes);

}