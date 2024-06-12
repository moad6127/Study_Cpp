#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int DayChange(string day)
{
    int result{};
    vector<int> d;
    while (true)
    {
        if (day.find('.') == string::npos)
        {
            d.push_back(stoi(day));
            break;
        }
        else
        {
            d.push_back(stoi(day.substr(0, day.find('.'))));
            day = day.substr(day.find('.') + 1);
        }
    }
    result = (d[0] * 12 * 28) + ((d[1] - 1) * 28) + d[2];
    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int toDay{};
    unordered_map<char, int> term;
    vector<int> checkPir;
    for (auto e : terms)
    {
        term[e[0]] =stoi(e.substr(e.find(' ') + 1));
    }
    toDay = DayChange(today);
    for (int i = 0; i< privacies.size();i++)
    {
        string day = privacies[i].substr(0, privacies[i].find(' '));
        char t = privacies[i].back();
        int Day = DayChange(day) + (term[t] * 28);
        if (toDay >= Day)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
int main()
{
    solution("2022.05.19", { "A 6", "B 12", "C 3" }, { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" });

}