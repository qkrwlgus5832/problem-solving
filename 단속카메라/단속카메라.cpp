#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
		if (a[0] == b[0]) {
			return a[1] > b[1];
		}
		return a[0] < b[0];
	});

	int currentSpot = routes[0][1];
	int answer = 1;
	for (int i = 1; i < routes.size(); i++) {
		if (routes[i][0] > currentSpot) {
			answer++;
			currentSpot = routes[i][1];
		}
		else {
			currentSpot = min(currentSpot, routes[i][1]);
		}
	}
	return answer;
}


int main() {
	solution({ {0, 12} ,{1, 12},{2, 12},{3, 12},{5, 6},{6, 12},{10, 12} });
}