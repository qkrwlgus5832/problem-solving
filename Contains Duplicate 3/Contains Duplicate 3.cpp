#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
	map <int, int> m;
	set <int> s;

	for (int i = 0; i < indexDiff; i++) {
		auto lowerBound = s.lower_bound(nums[i]);

		if (lowerBound != s.end() && abs(*lowerBound - nums[i]) <= valueDiff) {
			return true;
		}

		if (lowerBound != s.begin()) {
			auto lowerBoundBefore = lowerBound;
			lowerBoundBefore--;

			if (abs(*lowerBoundBefore - nums[i]) <= valueDiff) {
				return true;
			}
		}

		m[nums[i]]++;
		s.insert(nums[i]);
	}

	for (int i = indexDiff; i < nums.size(); i++) {
		auto lowerBound = s.lower_bound(nums[i]);

		if (lowerBound != s.end() && abs(*lowerBound - nums[i]) <= valueDiff) {
			return true;
		}

		if (lowerBound != s.begin()) {
			auto lowerBoundBefore = lowerBound;
			lowerBoundBefore--;

			if (abs(*lowerBoundBefore - nums[i]) <= valueDiff) {
				return true;
			}
		}

		m[nums[i - indexDiff]]--;
		if (m[nums[i - indexDiff]] == 0) {
			s.erase(nums[i - indexDiff]);
		}

		m[nums[i]]++;
		s.insert(nums[i]);
	}

	return false;
}

int main() {
	vector<int> v = { 1, 5, 9, 1, 5, 9 };

	cout << containsNearbyAlmostDuplicate(v, 2, 3);
}