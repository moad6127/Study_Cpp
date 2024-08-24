#include <string>
#include <vector>
#include <queue>
using namespace std;

int SToL[104][104];
int LToE[104][104];
const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int solution(vector<string> maps) {
    int answer = -1;
    queue<pair<int,int>> q;
    queue<pair<int, int>>q2;
    vector<pair<int, int>> info(3);
    int SL{};
    int LE{};
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++)
        {
            if (maps[i][j] == 'S')
            {
                info[0].first = i;
                info[0].second = j;
            }
            else if (maps[i][j] == 'E')
            {
                info[1].first = i;
                info[1].second = j;
            }
            else if (maps[i][j] == 'L')
            {
                info[2].first = i;
                info[2].second = j;
            }
        }
    }
    q.push(info[0]);
    while (q.size())
    {
        pair<int, int>now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if (ny < 0 || ny >= maps.size() || nx < 0 || nx >= maps[0].size())
            {
                continue;
            }
            if (maps[ny][nx] == 'X')
            {
                continue;
            }
            if (SToL[ny][nx] != 0)
            {
                continue;
            }
            SToL[ny][nx] = SToL[now.first][now.second] + 1;
            q.push({ ny,nx });
        }
    }
    q2.push(info[2]);
    while (q2.size())
    {
        pair<int, int>now = q2.front();
        q2.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if (ny < 0 || ny >= maps.size() || nx < 0 || nx >= maps[0].size())
            {
                continue;
            }
            if (maps[ny][nx] == 'X')
            {
                continue;
            }
            if (LToE[ny][nx] != 0)
            {
                continue;
            }
            LToE[ny][nx] = LToE[now.first][now.second] + 1;
            q2.push({ ny,nx });
        }
    }
    SL = SToL[info[2].first][info[2].second];
    LE = LToE[info[1].first][info[1].second];
    if (SL && LE)
    {
        answer = SL + LE;
    }

    return answer;
}

int main()
{
    solution({ "SOOOL", "XXXXX", "OOOOO", "OXXXX", "OOOOE" });
}