#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int now{};
    while (true)
    {
        int out{};
        if (now >= progresses.size())
        {
            break;
        }
        for (int i = now; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
        }
        if (progresses[now] >= 100)
        {
            for (now; now < progresses.size(); now++)
            {
                if (progresses[now] < 100)
                {
                    break;
                }
                out++;
            }
        }
        if (out)
        {
            answer.push_back(out);
        }
    }
    return answer;
}
int main()
{
    solution({ 93,30,55 }, { 1,30,5 });
}