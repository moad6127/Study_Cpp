#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        int check{};
        check = arr1[i] | arr2[i];
        temp.push_back(check);
    }
    for (int i = 0; i < n; i++)
    {
        string result;
        for (int j = 0; j < n; j++)
        {
            if (temp[i] & (1 << j))
            {
                result.push_back('#');
            }
            else
            {
                result.push_back(' ');
            }
        }
        reverse(result.begin(), result.end());
        answer.push_back(result);
    }
    return answer;
}

int main()
{
    solution(5, { 9, 20, 28, 18, 11 }, { 30, 1, 21, 17, 28 });
}