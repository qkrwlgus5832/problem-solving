#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int singleNumber(vector<int>& nums) {
	map<int, int> cache;

	int answer = 0;

	for (int i = 0; i < nums.size(); i++) {
		if (cache.count(nums[i]) == 0) {
			answer = nums[i];
			cache[nums[i]] = 1;
			continue;
		}

		cache[nums[i]] = cache[nums[i]] + 1;
	}
	
	for (const auto& kv : cache) {
		if (kv.second == 1) {
			return kv.first;
		}
	}
	
	return answer;
}

int main() {
	vector<int> v = { 1 };
	cout << singleNumber(v);
}