#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<int> dy = { 0,1,0,-1 };
vector<int> dx= { 1,0,-1,0 };

vector<vector<int>> solution(int n) {

    vector<vector<int>> answer(n,vector<int>(n,0));
    int dir{};
    int count{1};
    int x{}, y{};
    answer[y][x] = count++;
    while (true)
    {
        if (count > n * n)
        {
            break;
        }
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || answer[ny][nx] != 0)
        {
            dir = (dir + 1) % 4;
            continue;
        }
        answer[ny][nx] = count++;
        y = ny;
        x = nx;
    }
    return answer;
}
int main()
{
    vector<vector<int>> temp = solution(5);


    return 0;
}