#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string Step_1(string new_id)
{
    string temp;
    for (auto e : new_id)
    {
        if (e >= 'A' && e <= 'Z')
        {
            temp += tolower(e);
            continue;
        }
        temp += e;
    }
    return temp;
}
string Step_2(string new_id)
{
    string temp;
    for (auto e : new_id)
    {
        if ((e == '-' || e == '_' || e == '.')|| (e >= 'a' && e <= 'z' )|| (e >= '0' && e <= '9'))
        {
            temp += e;
        }
    }
    return temp;
}
string Step_3(string new_id)
{
    string temp;

    for (auto e : new_id)
    {
        if (!temp.empty() && temp.back() == '.')
        {
            if (e == '.')
            {
                continue;
            }
        }
        temp += e;
    }
    return temp;
}
void Step_4(string& new_id)
{
    if (new_id.front() == '.')
    {
        new_id = new_id.substr(1);
    }
    if (new_id.back() == '.')
    {
        new_id.pop_back();
    }
}
void Step_5(string& new_id)
{
    if (new_id.empty())
    {
        new_id.push_back('a');
    }
}
void Step_6(string& new_id)
{
    if (new_id.size() >= 16)
    {
        new_id = new_id.substr(0,15);
    }
    Step_4(new_id);
}
void Step_7(string& new_id)
{
    if (new_id.size() <= 2)
    {
        while (true)
        {
            if (new_id.size() == 3)
            {
                break;
            }
            new_id += new_id.back();
        }
    }
}
string solution(string new_id) {
    string answer = "";
    
    new_id = Step_1(new_id);
    new_id = Step_2(new_id);
    new_id = Step_3(new_id);
    Step_4(new_id);
    Step_5(new_id);
    Step_6(new_id);
    Step_7(new_id);
   
    answer = new_id;
    return answer;
}

int main()
{
    solution("...!@BaT#*..y.abcdefghijklm");
}