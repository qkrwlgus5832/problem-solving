#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[1000001];
int dp2[1000001];

int answer = 0;

int solution(vector<int> money) {
    int answer = 0;

    dp[0] = money[0];
    dp[1] = money[0];

    for (int i = 2; i < money.size() - 1; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }

    dp2[0] = 0;
    dp2[1] = money[1];

    for (int i = 2; i < money.size(); i++) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
    }

    return max(dp[money.size() - 2], dp2[money.size() - 1]);
}

int main() {
    cout << solution({ 1, 2, 3, 1 });
}