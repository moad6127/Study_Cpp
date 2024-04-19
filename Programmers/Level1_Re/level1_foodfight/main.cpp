#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "0";
    for (int i = food.size() - 1; i > 0; i--)
    {
        int size = food[i] / 2;
        char fc = i + '0';
        string temp(size,fc);
        answer = temp + answer;
        answer += temp;
    }
    return answer;
}
int main()
{
    solution({ 1,3,4,6 });
}