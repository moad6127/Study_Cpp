#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    vector<int> temp(n, 0);
    for (int i = 0; i < arr1.size(); i++)
    {
        temp[i] = arr1[i] | arr2[i];
    }

    for (int i = 0; i < temp.size(); i++)
    {
        string deString{};
        for (int j = 0; j < n; j++)
        {
            int check = (temp[i] >> j) & 1;
            if (check)
            {
                deString += "#";
            }
            else
            {
                deString += " ";
            }
        }
        reverse(deString.begin(), deString.end());
        answer.push_back(deString);
    }


    return answer;
}
int main()
{
    int n{ 5 };
    vector<int> arr1{ 9, 20, 28, 18, 11 };
    vector<int> arr2{ 30, 1, 21, 17, 28 };
    solution(n, arr1, arr2);
}