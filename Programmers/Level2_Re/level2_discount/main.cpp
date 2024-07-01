#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wantMap;
    for (int i = 0; i < want.size(); i++)
    {
        wantMap[want[i]] = number[i];
    }
    for (int startDay = 0; startDay <= discount.size() - 10; startDay++)
    {
        map<string, int> disMap;
        for (int day = startDay; day < startDay + 10; day++)
        {
            disMap[discount[day]]++;
        }
        if (wantMap == disMap)
        {
            answer++;
        }
    }
    return answer;
}
int main()
{
    solution({ "banana", "apple", "rice", "pork", "pot" }, { 3, 2, 2, 2, 1 }, { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" });

}