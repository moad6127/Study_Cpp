#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,0);
    int sum{sequence[0]};
    int st{};
    int en{};
    int len{987654321};
    while (true)
    {
        if (en >= sequence.size())
        {
            break;
        }
        if (st > en)
        {
            break;
        }
        if (sum == k)
        {
            if (len > en - st)
            {
                len = en - st;
                answer[0] = st;
                answer[1] = en;
            }
            sum -= sequence[st++];
            continue;
        }
        else if (sum < k)
        {
            sum += sequence[++en];
        }
        else
        {
            sum -= sequence[st++];
        }

    }
    return answer;
}
int main()
{
    solution({1,1,1,2,3,4,5 },5);
}