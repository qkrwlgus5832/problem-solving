#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[100001][4][3][2];

char phone[4][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*', '0', '#'}
};

pair <int, int> getCoordi(char x) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (phone[i][j] == x) {
                return { i,j };
            }
        }
    }
    return { -1, -1 };
}

int getDistance(char x, char y) {
    pair <int, int> coordiX = getCoordi(x);
    pair <int, int> coordiY = getCoordi(y);

    return abs(coordiX.first - coordiY.first) + abs(coordiX.second - coordiY.second) + 1;
}

int solution(string numbers) {
    int answer = 0;

    char leftHand = '4';
    char rightHand = '6';

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < 12; j++) {
            dp[i][]
        }
    }

    return answer;
}

int main() {
    cout << solution("5123");
}