#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

const string DIC{ "AEIOU" };
int now;
void Func(unordered_map<string, int>& dic, string words)
{

    if (words.size() > 5)
    {
        return;
    }
    dic[words] = now++;
    for (int i = 0; i < DIC.size(); i++)
    {
        words.push_back(DIC[i]);
        Func(dic, words);
        words.pop_back();
    }
    return;
}

int solution(string word) {
    now = 0;
    unordered_map<string, int> dic;
    Func(dic, "");
    return dic[word];
}
int main()
{
    solution("AAAAE");
}