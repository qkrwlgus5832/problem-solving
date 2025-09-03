#include <string>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

int dp[201][201] = { {-1,} };

int getCurrentCalSize(int start, int index, int end, vector<vector<int>>* matrix_sizes) {
    return (*matrix_sizes)[start][0] * (*matrix_sizes)[index][1] * (*matrix_sizes)[end][1];
}

void recursion(vector<vector<int>>* matrix_sizes, int start, int end) {
    int result = INT_MAX;

    if (start == end) {
        dp[start][end] = 0;
        return;
    }

    for (int i = start; i < end; i++) {
        if (dp[start][i] == -1) {
            recursion(matrix_sizes, start, i);
        }

        if (dp[i + 1][end] == -1) {
            recursion(matrix_sizes, i + 1, end);
        }

        result = min(result, dp[start][i] + dp[i + 1][end] + getCurrentCalSize(start, i, end, matrix_sizes));
    }

    dp[start][end] = result;
}

int solution(vector<vector<int>> matrix_sizes) {
    memset(dp, -1, sizeof(dp));
    recursion(&matrix_sizes, 0, matrix_sizes.size() - 1);
    return dp[0][matrix_sizes.size() - 1];
}

int main() {
    cout << solution({
        {5,3},
        {3, 10},
        {10, 6}
        });
}