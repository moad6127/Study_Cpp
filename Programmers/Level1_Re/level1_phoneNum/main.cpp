#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string temp;
    for (int i = 0; i < phone_number.size() - 4; i++)
    {
        temp += '*';
    }
    phone_number.replace(phone_number.begin(), phone_number.begin() + phone_number.size() - 4,temp);
    return phone_number;
}