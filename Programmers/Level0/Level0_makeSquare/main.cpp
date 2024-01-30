#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int ySize = arr.size();
    int xSize = arr[0].size();
    if (ySize > xSize)
    {
        for (auto& e : arr)
        {
            e.push_back(0);
        }
    }
    else if(ySize < xSize)
    {
        for (int i = 0; i < ySize - xSize; i++)
        {
            vector<int> temp(ySize, 0);
            arr.push_back(temp);
        }
    }

    return arr;
}
int main()
{
    solution({ {57, 192, 534, 2},{9, 345, 192, 999} });
}