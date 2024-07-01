#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int eleSize = elements.size();
    unordered_set<int> Sums;

    for (int size = 1; size <= eleSize; size++)
    {
        for (int start = 0; start < eleSize; start++)
        {
            int sum{};
            for (int e = start; e < start + size; e++)
            {
                sum += elements[e % eleSize];
            }
            Sums.insert(sum);
        }
    }
    return Sums.size();
}
int main()
{
    solution({ 7,9,1,1,4 });
}