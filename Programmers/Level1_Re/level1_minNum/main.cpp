#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    auto e = min_element(arr.begin(),arr.end());
    arr.erase(e);
    return arr.empty() ? vector<int>{-1}: arr;
}