#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for (left; left <= right; left++)
    {
        vector<int> temp;
        for (int i = 1; i <= left; i++)
        {
            if (left % i == 0)
            {
                temp.push_back(i);
            }
        }
        if (temp.size() % 2)
        {
            answer -= left;
        }
        else
        {
            answer += left;
        }
    }
    return answer;
}
int main()
{
    solution(13, 17);
}