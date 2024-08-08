#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> LIST{'4', '1', '2', '4'};
string solution(int n) {
    string answer = "";
    while (true)
    {
        if (n <= 3)
        {
            answer += LIST[n];
            break;
        }
        int temp = n % 3;
        answer += LIST[temp];
        n /= 3;
        if (!temp)
        {
            n--;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
int main()
{
    solution(9);
}