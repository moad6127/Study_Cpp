#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int sum{};
    for (auto e : arr)
    {
        sum += e;
    }
    
    return double(sum) / arr.size();;
}