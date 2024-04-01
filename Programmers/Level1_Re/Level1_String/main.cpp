#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (!(s.size() == 4 || s.size() == 6))
    {
        answer = false;
    }
    for (auto e : s)
    {
        if (!(e >= '0' && e <= '9'))
        {
            answer = false;
        }
    }
    return answer;
}
int main()
{
    solution("a234");
}