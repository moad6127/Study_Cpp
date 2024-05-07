#include <string>
#include <vector>

using namespace std;
const vector<string> BAB{"aya", "ye", "woo", "ma"};

bool Check(string bab,string prev)
{
    if (bab.empty())
    {
        return  true;
    }
    for (auto e : BAB)
    {
        if (prev == e)
        {
            continue;
        }
        if (bab.find(e) == 0)
        {
            bab = bab.substr(e.size());
            if (Check(bab,e))
            {
                return true;
            }
        }
    }
    return false;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (auto e : babbling)
    {
        if (Check(e,""))
        {
            answer++;
        }
    }
    return answer;
}
int main()
{
    solution({ "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" });
}