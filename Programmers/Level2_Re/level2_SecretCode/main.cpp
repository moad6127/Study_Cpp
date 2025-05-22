#include <string>
#include <vector>

using namespace std;

int answer;

bool check(vector<int>& code, vector<vector<int>>& q, vector<int>& ans)
{
    for (int i = 0; i < q.size();i++)
    {
        vector<int> visited(32, 0);
        int cnt{};
        for (auto e : q[i])
        {
            visited[e]++;
        }
        for (auto e : code)
        {
            cnt += visited[e];
        }
        if (ans[i] != cnt)
        {
            return false;
        }
    }
    return true;
}
void Func(int start,int n,vector<int>& code,  vector<vector<int>>& q, vector<int>& ans)
{
    if (code.size() == 5)
    {
        answer += check(code, q, ans);
        return;
    }
    for (int i = start + 1; i <= n;i++)
    {
        code.push_back(i);
        Func(i, n, code, q, ans);
        code.pop_back();
    }
}
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    answer = 0;
    vector<int> code;
    Func(0, n, code, q, ans);
    return answer;
}

int main()
{
    vector<vector<int>> q{ {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {3, 7, 8, 9, 10},
        {2, 5, 7, 9, 10},
        {3, 4, 5, 6, 7} };
    vector<int> ans{ 2, 3, 4, 3, 3 };
    solution(10, q, ans);
}