#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int visited[104][104];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int dfs(vector<string>& maps,int y, int x)
{
    visited[y][x] = 1;
    int result{};
    result = maps[y][x] - '0';
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= maps.size() || nx < 0 || nx >= maps[0].size())
        {
            continue;
        }
        if (maps[ny][nx] != 'X' && !visited[ny][nx])
        {
            result += dfs(maps, ny, nx);
        }
    }
    return result;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++)
        {
            if (maps[i][j] != 'X' && !visited[i][j])
            {
                answer.push_back(dfs(maps,i,j));
            }
        }
    }
    if (!answer.empty())
    {
        sort(answer.begin(), answer.end());
    }
    else
    {
        answer.push_back(-1);
    }

    return answer;
}
int main()
{
    solution({ "X591X","X1X5X","X231X", "1XXX1" });
}