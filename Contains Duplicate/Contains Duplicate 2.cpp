#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	map<int, int> cache;

	for (int i = 0; i < nums.size(); i++) {
		if (cache.count(nums[i]) != 0) {
			if (i - cache[nums[i]] <= k) {
				return true;
			}
		}
		cache[nums[i]] = i;

	}

	return false;
}

int main() {
	vector<int> v = { 1, 0, 1, 1};
	cout << containsNearbyDuplicate(v, 1);
}