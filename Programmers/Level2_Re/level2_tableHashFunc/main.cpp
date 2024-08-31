#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CHECK;

bool comp(vector<int>& a, vector<int>& b)
{
    if (a[CHECK] == b[CHECK])
    {
        return a[0] > b[0];
    }
    return a[CHECK] < b[CHECK];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    CHECK = col - 1;
    sort(data.begin(), data.end(), comp);
    for (int i = row_begin - 1; i < row_end; i++)
    {
        int S{};
        for (auto e : data[i])
        {
            S += (e % (i + 1));
        }
        if (answer == 0)
        {
            answer = S;
        }
        else
        {
            answer = (answer ^ S);
        }
    }
    return answer;
}

int main()
{
    solution({ {2,2,6} ,{1,5,10},{4,2,9},{3,8,3} }, 2, 2, 3);
}