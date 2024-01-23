#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52);
    for (auto e : my_string)
    {
        if (e >= 'A' && e <= 'Z')
        {
            answer[e - 'A']++;
        }
        else
        {
            answer[e - 'a' + 26]++;
        }
    }

    return answer;
}
int main()
{
    string s{ "Programmers" };
    solution(s);
}