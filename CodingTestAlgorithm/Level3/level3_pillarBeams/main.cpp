#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool CheckPoint(int y, int x,int a, vector<string>& maps)
{
    if (a)
    {
        if (maps[y - 1][x] == 'Y')
        {
            return true;
        }
        if (maps[y - 1][x + 1] == 'Y')
        {
            return true;
        }
        if (maps[y][x - 1] == 'X' && maps[y][x + 1] == 'X')
        {
            return true;
        }
    }
    else
    {
        if (y == 0)
        {
            return true;
        }
        if (maps[y - 1][x] == 'Y')
        {
            return true;
        }
        if (maps[y][x - 1] == 'X')
        {
            return true;
        }
        if (maps[y][x] == 'X')
        {
            return true;
        }
    }

    return false;
}

bool removePoint(int y, int x,int a, vector<string>& maps)
{
    maps[y][x] = '.';
    if (a)
    {
        if (maps[y][x] == 'Y' && !CheckPoint(y, x, 0, maps))
        {
            return false;
        }
        if (maps[y][x + 1] == 'Y' && !CheckPoint(y, x + 1, 0, maps))
        {
            return false;
        }
        if (maps[y][x - 1] == 'X' && !CheckPoint(y, x-1, 1, maps))
        {
            return false;
        }
        if (maps[y][x + 1] == 'X' && !CheckPoint(y, x + 1, 1, maps))
        {
            return false;
        }
    }
    else
    {
        if (maps[y + 1][x] == 'Y' && !CheckPoint(y + 1, x, 0, maps))
        {
            return false;
        }
        if (maps[y + 1][x] == 'X' && !CheckPoint(y+1,x, 1, maps))
        {
            return false;
        }
        if (maps[y + 1][x - 1] == 'X' && !CheckPoint(y + 1, x - 1, 1, maps))
        {
            return false;
        }
    }
    return true;
}

bool comp(vector<int>& a, vector<int>& b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<string> maps(n + 1,string(n + 1,'.'));

    for (auto e : build_frame)
    {
        int x = e[0];
        int y = e[1];
        int a = e[2];
        int b = e[3];
        if (b)
        {
            if (CheckPoint(y, x, a, maps))
            {
                if (a)
                {
                    maps[y][x] = 'X';
                }
                else
                {
                    maps[y][x] = 'Y';
                }
            }
        }
        else
        {
            if (!removePoint(y, x, a, maps))
            {
                if (a)
                {
                    maps[y][x] = 'X';
                }
                else
                {
                    maps[y][x] = 'Y';
                }
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (maps[i][j] == 'Y')
            {
                answer.push_back({ j,i,0 });
            }
            if (maps[i][j] == 'X')
            {
                answer.push_back({ j,i,1 });
            }
        }
    }
    sort(answer.begin(), answer.end(), comp);

    return answer;
}

int main()
{
    vector<vector<int>> build_frame {{0, 0, 0, 1}, { 2, 0, 0, 1 }, { 4, 0, 0, 1 }, { 0, 1, 1, 1 }, { 1, 1, 1, 1 },
        { 2, 1, 1, 1 }, { 3, 1, 1, 1 }, { 2, 0, 0, 0 }, { 1, 1, 1, 0 }, { 2, 2, 0, 1 }};

    solution(5, build_frame);
}