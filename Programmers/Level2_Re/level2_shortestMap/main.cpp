#include<vector>
#include <queue>
using namespace std;
const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };
int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visit(n, vector<int>(m, 0));
    visit[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    while (q.size())
    {
        pair<int, int> now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            {
                continue;
            }
            if (visit[ny][nx])
            {
                continue;
            }
            if (maps[ny][nx] == 0)
            {
                continue;
            }
            visit[ny][nx] = visit[now.first][now.second] + 1;
            q.push({ ny,nx });
        }
    }
    return visit[n-1][m-1] ? visit[n-1][m-1] : answer;
}
int main()
{
    vector<vector<int> > maps{{1, 0, 1, 1, 1}, { 1, 0, 1, 0, 1 }, { 1, 0, 1, 1, 1 }, { 1, 1, 1, 0, 1 }, { 0, 0, 0, 0, 1 }};
    solution(maps);
}