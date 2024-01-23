#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    int i{};
    while (true)
    {
        if (i >= arr.size())
        {
            break;
        }
        if (stk.size())
        {
            if (stk.back() < arr[i])
            {
                stk.push_back(arr[i++]);
            }
            else
            {
                stk.pop_back();
            }
        }
        else
        {
            stk.push_back(arr[i++]);
        }
    }
    return stk;
}