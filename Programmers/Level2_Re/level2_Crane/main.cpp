#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

void RemoveSide(vector<vector<char>>& map, char a)
{
    vector<vector<int>> visited(map.size(), vector<int>(map[0].size(), 0));
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visited[0][0] = 1;
    vector<pair<int, int>> removeBox;
    while (q.size())
    {
        pair<int, int> now = q.front();
        q.pop();
        for (int i = 0;i < 4;i++)
        {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if (ny < 0 || ny >= map.size() || nx < 0 || nx >= map[0].size())
            {
                continue;
            }
            if (visited[ny][nx])
            {
                continue;
            }
            if (map[ny][nx] == a)
            {
                removeBox.push_back({ ny,nx });
            }
            if (map[ny][nx] == 0)
            {
                q.push({ ny,nx });
                visited[ny][nx] = 1;
            }
        }
    }
    for (pair<int,int> box : removeBox)
    {
        map[box.first][box.second] = 0;
    }
}
void RemoveAll(vector<vector<char>>& map, char a)
{
    for (int i = 0;i < map.size();i++)
    {
        for (int j = 0; j < map[i].size();j++)
        {
            if (map[i][j] == a)
            {
                map[i][j] = 0;
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int y = storage.size() + 2;
    int x = storage[0].size() + 2;
    vector<vector<char>> newMap(y, vector<char>(x, 0));
    for (int i = 1; i <= storage.size();i++)
    {
        for (int j = 1; j <= storage[0].size();j++)
        {
            newMap[i][j] = storage[i - 1][j - 1];
        }
    }
    for (int i = 0; i < requests.size();i++)
    {
        if (requests[i].size() == 1)
        {
            RemoveSide(newMap, requests[i][0]);
        }
        else
        {
            RemoveAll(newMap, requests[i][0]);
        }
    }
    for (int i = 0; i < y;i++)
    {
        for (int j = 0;j < x;j++)
        {
            if (newMap[i][j])
            {
                answer++;
            }
        }
    }
    return answer;
}

int main()
{
    vector<string> stor{ "AZWQY", "CAABX", "BBDDA", "ACACA" };
    vector<string> req{ "A", "BB", "A" };
    solution(stor, req);
}