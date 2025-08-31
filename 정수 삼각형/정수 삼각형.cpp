#include <string>
#include <vector>

using namespace std;

int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int j = 0; j < triangle[triangle.size() - 1].size(); j++) {
        dp[triangle.size() - 1][j] = triangle[triangle.size() - 1][j];
    }

    for (int i = triangle.size() - 2; i >= 0; i--) {
        for (int j = 0; j < triangle[i].size(); j++) {
            dp[i][j] = max(triangle[i][j] + dp[i + 1][j],  triangle[i][j] + dp[i + 1][j + 1]);
        }
    }

    return dp[0][0];
}

int main() {
    solution({ {7}, {3,8} });
}