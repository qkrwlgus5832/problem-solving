#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int maxSubArray(vector<int>& nums) {
	int maxValue = nums[0];

	int dp[10001] = { 0, };
	int answer = nums[0];

	dp[0] = nums[0];
	int minValue = min(0, dp[0]);

	for (int i = 1; i < nums.size(); i++) {
		dp[i] = dp[i - 1] + nums[i];

		answer = max(answer, dp[i] - minValue);

		if (minValue > dp[i]) {
			minValue = dp[i];
		}

	}

	return answer;
}

int main() {
	vector<int> v = { 5, 4, -1, 7, 8 };

	cout << maxSubArray(v);
}