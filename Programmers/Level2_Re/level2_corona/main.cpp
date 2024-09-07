#include <string>
#include <vector>

using namespace std;

const int dy[]{ -1,0,1,0, -1,-1,1,1 };
const int dx[]{ 0,1,0,-1,-1,1,-1,1 };

bool Check(vector<string>& str, int y, int x)
{
    //상하좌우 체크
    for (int i = 0; i < 4; i++)
    {
        int ny = y;
        int nx = x;
        for (int j = 0; j < 2; j++)
        {
            ny += dy[i];
            nx += dx[i];
            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
            {
                continue;
            }
            if (str[ny][nx] == 'X')
            {
                break;
            }
            if (str[ny][nx] == 'P')
            {
                return false;
            }
        }
    }
    //대각선 체크
    for (int i = 4; i < 8; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
        {
            continue;
        }
        if (str[ny][nx] == 'X')
        {
            continue;
        }
        if (str[ny][nx] == 'P')
        {
            if (str[ny][x] == 'X' && str[y][nx] == 'X')
            {
                continue;
            }
            return false;
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto str : places)
    {
        bool flag{ false };
        for (int i = 0; i < 5; i++)
        {
            if (flag)
            {
                break;
            }
            for (int j = 0; j < 5; j++)
            {
                if (flag)
                {
                    break;
                }
                if (str[i][j] == 'P')
                {
                    if (!Check(str,i, j))
                    {
                        flag = true;
                    }
                }
            }
        }
        if (flag)
        {
            answer.push_back(0);
        }
        else
        {
            answer.push_back(1);
        }
    }
    return answer;
}

int main()
{
    solution({ { "POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP" },{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} });
}