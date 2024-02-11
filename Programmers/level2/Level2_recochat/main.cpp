#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> board) {
    int answer = 0;
    int y{}, x{}, gY{}, gX{};
    int ySize = board.size();
    int xSize = board[0].size();
    vector<int> dy{-1, 0, 1, 0};
    vector<int> dx{0, -1, 0, 1};
    vector<vector<int>> vv(ySize, vector<int>(xSize, 9876543));
    for (int i = 0; i < ySize; i++)
    {
        for (int j = 0; j < xSize; j++)
        {
            if (board[i][j] == 'R')
            {
                y = i;
                x = j;
            }
            if (board[i][j] == 'G')
            {
                gY = i;
                gX = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({ y,x });
    vv[y][x] = 0;
    while (q.size())
    {
        pair<int,int> now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny{ now.first };
            int nx{ now.second };
            while (true)
            {
                ny += dy[i];
                nx += dx[i];
                if (ny < 0 || ny >= ySize || nx < 0 || nx >= xSize || board[ny][nx] == 'D')
                {
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }
            }
            if (ny == now.first && nx == now.second)
            {
                continue;
            }
            if (vv[ny][nx] < vv[now.first][now.second] + 1)
            {
                continue;
            }
            vv[ny][nx] = vv[now.first][now.second] + 1;
            q.push({ ny,nx });
        }
    }
    if (vv[gY][gX] == 9876543)
    {
        answer = -1;
    }
    else
    {
        answer = vv[gY][gX];
    }
    return answer;
}
int main()
{
    vector<string> board{"...D..R", ".D.G...", "....D.D", "D....D.", "..D...."};
    solution(board);
}