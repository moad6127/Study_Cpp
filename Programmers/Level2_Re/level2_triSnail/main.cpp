#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int p = n;
    vector<vector<int>> check(n, vector<int>(n, 0));
    int x{-1}, y{};
    int cnt{};
    while (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            check[++x][y] = ++cnt;
        }
        for(int i = 0 ; i<n-1;i++)
        {
            check[x][++y] = ++cnt;
        }
        for (int i = 0; i < n - 2; i++)
        {
            check[--x][--y] = ++cnt;
        }
        n -= 3;
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            answer.push_back(check[i][j]);
        }
    }
    return answer;
}

int main()
{
    solution(4);
}