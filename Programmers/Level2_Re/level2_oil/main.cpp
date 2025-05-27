#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>


using namespace std;

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,-1,0,1 };

int solution(vector<vector<int>> land) {
    int answer = 0;
    unordered_map<int, int> oils;
    int n = land.size();
    int m = land[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int nums{ 2 };

    for (int i = 0;i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if (land[i][j] == 0)
            {
                continue;
            }
            if (visited[i][j])
            {
                continue;
            }
            queue<pair<int, int>> q;
            q.push({ i,j });
            int cnt{1};
            visited[i][j] = nums;
            while (q.size())
            {
                pair<int, int> l = q.front();
                q.pop();
                for (int i = 0; i < 4;i++)
                {
                    int ny = l.first + dy[i];
                    int nx = l.second + dx[i];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                    {
                        continue;
                    }
                    if (visited[ny][nx])
                    {
                        continue;
                    }
                    if (land[ny][nx] == 0)
                    {
                        continue;
                    }
                    q.push({ ny,nx });
                    visited[ny][nx] = nums;
                    cnt++;
                }
            }
            oils[nums++] = cnt;
        }
    }

    for (int i = 0;i < m;i++)
    {
        vector<int> checkList(nums + 1, 0);
        int count{};
        for (int j = 0; j < n;j++)
        {
            if (visited[j][i] == 0)
            {
                continue;
            }
            checkList[visited[j][i]] = 1;
        }
        for (int k = 0; k < checkList.size();k++)
        {
            if (checkList[k])
            {
                count += oils[k];
            }
        }
        answer = max(answer, count);
    }

    return answer;
}
int main()
{
    vector<vector<int>> land{ {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 1, 1} };
    solution(land);
}