#include <string>
#include <vector>

using namespace std;

const int dy[3]{ 1,1,0 };
const int dx[3]{ 1,0,1 };
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while (true)
    {
        vector<pair<int, int>> list;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                char check{ board[i][j] };
                bool flag = false;
                if (check == '#')
                {
                    continue;
                }
                for (int k = 0; k < 3; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (board[ny][nx] != check)
                    {
                        flag = true;
                    }
                    if (flag)
                    {
                        break;  
                    }
                }
                if (!flag)
                {
                    list.push_back({ i,j });
                }
            }
        }
        if (list.empty())
        {
            break;
        }
        for (auto e : list)
        {
            int y = e.first;
            int x = e.second;
            if (board[y][x] != '#')
            {
                board[y][x] = '#';
                answer++;
            }
            for (int i = 0; i < 3; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (board[ny][nx] != '#')
                {
                    board[ny][nx] = '#';
                    answer++;
                }
            }
        }
        //move
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != '#')
                {
                    continue;
                }
                int ny = i;
                while (true)
                {
                    if (ny < 0)
                    {
                        break;
                    }
                    if (board[ny][j] != '#')
                    {
                        break;
                    }
                    ny--;
                }
                if (ny >= 0)
                {
                    board[i][j] = board[ny][j];
                    board[ny][j] = '#';
                }
            }
        }
    }
    return answer;
}

int main()
{
    solution(10, 10, { "DDABBAABBA",
"AAAAAABBBA",
"DDACCBBBAA",
"DDABBBBBAA",
"AAABBABBBA",
"CCADDAABBB",
"CCADDAABBB",
"BBACCABBBA",
"BBAAABBBAA",
"DDABBBBAAA" });
}