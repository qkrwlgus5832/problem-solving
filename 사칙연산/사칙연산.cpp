#include <vector>
#include <string>
#include <algorithm>
#include <memory.h>
#include <iostream>

using namespace std;

int minDp[202][202] = { INT_MAX, };
int maxDp[202][202] = { INT_MIN, };

void recursion(vector<string> arr, int start, int end) {
    if (start == end) {

        maxDp[start][end] = stoi(arr[start]);
        minDp[start][end] = stoi(arr[start]);
        return;
    }

    for (int i = start; i < end; i++) {
        if (arr[i][0] == '+') {
            if (maxDp[start][i - 1] == INT_MIN) {
                recursion(arr, start, i - 1);
            }

            if (maxDp[i + 1][end] == INT_MIN) {
                recursion(arr, i + 1, end);
            }

            maxDp[start][end] = max(maxDp[start][end], maxDp[start][i - 1] + maxDp[i + 1][end]);
            minDp[start][end] = min(minDp[start][end], minDp[start][i - 1] + minDp[i + 1][end]);
        }

        else if (arr[i][0] == '-') {
            if (minDp[start][i - 1] == INT_MAX) {
                recursion(arr, start, i - 1);
            }

            if (minDp[i + 1][end] == INT_MAX) {
                recursion(arr, i + 1, end);
            }

            maxDp[start][end] = max(maxDp[start][end], maxDp[start][i - 1] - minDp[i + 1][end]);
            minDp[start][end] = min(minDp[start][end], minDp[start][i - 1] - maxDp[i + 1][end]);
        }
    }
}

int solution(vector<string> arr)
{   
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            minDp[i][j] = INT_MAX;
            maxDp[i][j] = INT_MIN;
        }
    }

    recursion(arr, 0, arr.size() - 1);
    return maxDp[0][arr.size() - 1];
}

int main() {
    cout << solution({ "1", "-", "3", "+", "5", "-", "8" });
}