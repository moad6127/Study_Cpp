#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {


	switch (n)
	{
	case 1:
	{
		vector<int> answer(num_list.begin(), num_list.begin() + slicer[1] + 1);
		return answer;
	}
	case 2:
	{
		vector<int> answer(num_list.begin() + slicer[0], num_list.end());
		return answer;
	}
	case 3:
	{
		vector<int> answer(num_list.begin() + slicer[0], num_list.begin() + slicer[1] + 1);
		return answer;
	}
	case 4:
	{
		vector<int> answer;
		for (int i = slicer[0]; i <= slicer[1]; i += slicer[2])
		{
			answer.push_back(num_list[i]);
		}
		return answer;
	}
	}
}