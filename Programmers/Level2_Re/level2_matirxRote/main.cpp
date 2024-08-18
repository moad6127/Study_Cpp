#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };

int Rot(vector<vector<int>>& v, vector<int> quer)
{
    int dir{};
    int Min{ 987654321 };
    int ny = quer[0] - 1;
    int nx = quer[1] - 1;
    vector<pair<int, int>> nextLoc;
    vector<int> nowInt;
    while (true)
    {
        if (dir >= 4)
        {
            break;
        }
        int nexty = ny + dy[dir];
        int nextx = nx + dx[dir];
        if (nexty > quer[2] - 1 || nexty < quer[0] - 1 || nextx > quer[3] - 1 || nextx < quer[1] - 1)
        {
            dir++;
            continue;
        }
        nextLoc.push_back({ nexty,nextx });
        nowInt.push_back(v[ny][nx]);
        Min = min(Min, v[ny][nx]);
        ny = nexty;
        nx = nextx;
    }
    for (int i = 0; i < nextLoc.size(); i++)
    {
        v[nextLoc[i].first][nextLoc[i].second] = nowInt[i];
    }
    return Min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> v;
    int cnt{ 1 };
    for (int i = 0; i <rows; i++)
    {
        vector<int> tempV;
        for (int j = 0; j < columns; j++)
        {
            tempV.push_back(cnt++);
        }
        v.push_back(tempV);
    }
    for (auto e : queries)
    {
        answer.push_back(Rot(v, e));
    }

    return answer;
}
int main()
{
    solution(6, 6, { {2,2,5,4},{3,3,6,6},{5,1,6,3} });
}