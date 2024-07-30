#include <string>
#include <vector>

using namespace std;


string quard(vector<string>& arr,int y, int x, int size)
{
    if (size == 1)
    {
        return string(1,arr[y][x]);
    }
    int check = arr[y][x];
    string res;
    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (check != arr[i][j])
            {
                res += quard(arr,y, x, size / 2);
                res += quard(arr,y, x + size / 2, size / 2);
                res += quard(arr,y + size / 2, x, size / 2);
                res += quard(arr,y + size / 2, x + size / 2, size / 2);
                return res;
            }
        }
    }
    return string(1, arr[y][x]);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2,0);
    vector<string> stArr;
    for (auto e : arr)
    {
        string temp;
        for (auto k : e)
        {
            temp.push_back('0' + k);
        }
        stArr.push_back(temp);
    }
    string cntSt = quard(stArr, 0, 0, arr.size());
    for (auto e : cntSt)
    {
        if (e == '1')
        {
            answer[1]++;
        }
        else
        {
            answer[0]++;
        }
    }
    return answer;
}

int main()
{
    solution({ {1, 1, 0, 0},{1, 0, 0, 0},{1, 0, 0, 1},{1, 1, 1, 1} });
}