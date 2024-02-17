#include <string>
#include <vector>

using namespace std;

vector<int> Inte(int k)
{
    vector<int> result;
    result.push_back(k);
    while (true)
    {
        if (k <= 1)
        {
            break;
        }
        if (k % 2)
        {
            k = (k * 3) + 1;
        }
        else
        {
            k /= 2;
        }
        result.push_back({ k });
    }

    return result;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> integral = Inte(k);
    int n = integral.size() - 1;
    vector<double> area(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        double temp{};
        temp = (integral[i - 1] + integral[i]) / (double)2;
        area[i] = temp;
    }

    for (auto e : ranges)
    {
        double temp{};
        if (e[0] > n + e[1])
        {
            answer.push_back(-1.0);
            continue;
        }
        for (int i = e[0] + 1; i <= n + e[1]; i++)
        {
            temp += area[i];
        }
        answer.push_back(temp);
    }

    return answer;
}

int main()
{
    vector<vector<int>> range{{0, 0}, { 1,-2 }, { 3,-3 }};
    solution(3, range);
}