#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void moveZeroes(vector<int>& nums) {
	
	int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != 0) {
			nums[i - count] = nums[i];
		}
		else {
			count++;
		}
	}

	for (int i = 0; i < count; i++) {
		nums[nums.size() - 1 - i] = 0;
	}
}

int main() {
	vector<int> v = { 0, 1, 0, 3, 12 };

	moveZeroes(v);
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}