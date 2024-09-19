#include <string>
#include <vector>

using namespace std;

vector<int> CollFunc(int k)
{
    vector<int> result;
    while (true)
    {
        result.push_back(k);
        if (k == 1)
        {
            break;
        }
        if (k & 1)
        {
            k *= 3;
            k++;
        }
        else
        {
            k /= 2;
        }
    }
    return result;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> Coll = CollFunc(k);
    vector<double> size;
    int n = Coll.size() - 1;
    for (int i = 1; i < Coll.size(); i++)
    {
        double s = (double)(Coll[i - 1] + Coll[i]) / 2;
        size.push_back(s);
    }
    for (auto ran : ranges)
    {
        double temp{};
        if (ran[0] > n + ran[1])
        {
            answer.push_back(-1);
            continue;
        }
        for (int i = ran[0]; i < n + ran[1]; i++)
        {
            temp += size[i];
        }
        answer.push_back(temp);
    }

    return answer;
}

int main()
{
    solution(3, { {0, 0},{1, -2},{3, -3}});
}