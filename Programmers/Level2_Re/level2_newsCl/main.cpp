#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    vector<string> st1;
    vector<string>st2;
    for (int i = 1; i < str1.size(); i++)
    {
        string temp;

        if (!(str1[i - 1] >= 'a' && str1[i - 1] <= 'z'))
        {
            continue;
        }
        if (!(str1[i] >= 'a' && str1[i] <= 'z'))
        {
            continue;
        }
        temp.push_back(str1[i - 1]);
        temp.push_back(str1[i]);
        st1.push_back(temp);
    }
    for (int i = 1; i < str2.size(); i++)
    {
        string temp;

        if (!(str2[i - 1] >= 'a' && str2[i - 1] <= 'z'))
        {
            continue;
        }
        if (!(str2[i] >= 'a' && str2[i] <= 'z'))
        {
            continue;
        }
        temp.push_back(str2[i - 1]);
        temp.push_back(str2[i]);
        st2.push_back(temp);
    }
    sort(st1.begin(), st1.end());
    sort(st2.begin(), st2.end());
    vector<string> UString(st1.size() + st2.size());
    auto itr = set_union(st1.begin(), st1.end(), st2.begin(), st2.end(), UString.begin());
    UString.erase(itr, UString.end());
    double a =  st1.size() + st2.size();
    double b = UString.size();
    a -= b;


    answer = a / b * 65536;
    if (a == 0 && b == 0)
    {
        answer = 65536;
    }


    return answer;
}
int main()
{
    solution("aa1+aa2", "	AAAA12");
}