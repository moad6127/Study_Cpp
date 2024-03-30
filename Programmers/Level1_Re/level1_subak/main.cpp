#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for (int i = 0; i < n; i++)
    {
        i % 2 ? answer += "¹Ú" : answer += "¼ö";
    }
    return answer;
}