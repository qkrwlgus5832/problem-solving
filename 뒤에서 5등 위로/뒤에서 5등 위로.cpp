#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> solution(vector<int> num_list) {
	sort(num_list.begin(), num_list.end());
	
	deque<int> de = deque<int>(num_list.begin(), num_list.end());

	int numListSize = num_list.size();
	int deuqePopSize = min(5, numListSize);

	for (int i = 0; i < deuqePopSize; i++) {
		de.pop_front();
	}

	return vector<int>(de.begin(), de.end());
}

