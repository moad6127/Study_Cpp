#include <string>
#include <vector>

using namespace std;

const string LAT{ "cafelatte" };

int solution(vector<string> order) {
    int answer = 0;
    for (auto e : order)
    {
        if (e.find(LAT) != string::npos)
        {
            answer += 5000;
        }
        else
        {
            answer += 4500;
        }      
    }
    return answer;
}