#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> checkList;

bool checkPrim(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int Func(string& numbers, vector<bool> visited,int here, string str)
{
    int res{};
    str += numbers[here];
    visited[here] = 1;
    if(checkList.insert(stoi(str)).second && checkPrim(stoi(str)))
    {
        res++;
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            res += Func(numbers, visited, i, str);
            visited[i] = 0;
        }
    }
    return res;
}

int solution(string numbers) {
    int answer = 0;
    vector<bool> visited(numbers.size(), 0);
    for (int i = 0; i < numbers.size(); i++)
    {
        answer += Func(numbers, visited, i,"");
    }
    return answer;
}

int main()
{
    solution("17");
}