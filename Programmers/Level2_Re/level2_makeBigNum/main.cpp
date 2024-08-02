#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int size = number.size() - k;
    int start{};
    for (int i = 0; i < size; i++)
    {
        char maxInt = number[start];
        int maxidx = start;
        for (int j = start + 1; j <= k + i; j++)
        {
            if (number[j] > maxInt)
            {
                maxInt = number[j];
                maxidx = j;
            }
        }
        start = maxidx + 1;
        answer += maxInt;
    }
    return answer;
}

int main()
{
    solution("4177252841",4);
}