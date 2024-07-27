#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (auto e : numbers)
    {
        long long next = e;
        while (true)
        {
            next++;
            int cnt{};
            for (long long i = 0; i < 32; i++)
            {
                if ((1&(e >> i)) !=(1&(next >> i)))
                {
                    cnt++;
                }
            }
            if (cnt <= 2)
            {
                answer.push_back(next);
                break;
            }
        }
    }
    return answer;
}
int main()
{
    solution({ 2,7 });
}