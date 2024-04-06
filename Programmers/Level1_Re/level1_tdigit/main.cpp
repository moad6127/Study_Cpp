#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string temp;
    while (n)
    {
        temp += (n % 3) + '0';
        n /= 3;
    }
    int i{ 1 };
    while (temp.size())
    {
        answer += (temp.back() - '0') * i;
        temp.pop_back();
        i *= 3;
    }
    return answer;
}

int main()
{
    solution(45);
}