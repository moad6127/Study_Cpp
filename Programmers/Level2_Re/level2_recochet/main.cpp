#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };

int solution(vector<string> board) {
    int answer = 0;
    pair<int, int> RLoc;
    pair<int, int> GLoc;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 'R')
            {
                RLoc = { i,j };
            }
            if (board[i][j] == 'G')
            {
                GLoc = { i,j };
            }
        }
    }
    queue<pair<int, int>> q;
    vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), -1));
    q.push(RLoc);
    visited[RLoc.first][RLoc.second] = 0;
    while (q.size())
    {
        pair<int, int>now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
            {
                continue;
            }
            if (board[ny][nx] == 'D')
            {
                continue;
            }
            while (true)
            {
                ny += dy[i];
                nx += dx[i];
                if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
                {
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }
                if (board[ny][nx] == 'D')
                {
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }
            }
            if (visited[ny][nx] != -1)
            {
                continue;
            }
            visited[ny][nx] = visited[now.first][now.second] + 1;
            q.push({ ny,nx });
        }

    }
    return visited[GLoc.first][GLoc.second];
}
int main()
{
    solution({ ".D.R", "....", ".G..", "...D" });
}