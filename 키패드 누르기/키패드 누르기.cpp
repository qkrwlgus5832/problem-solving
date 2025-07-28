#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char phone[4][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

pair <int, int> getCoordi(char x) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (phone[i][j] == x) {
                return { i, j };
            }
        }
    }
}

int getDistance(pair <int, int> a, pair <int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    char leftHand = '*';
    char rightHand = '#';

    for (int i = 0; i < numbers.size(); i++) {
        char x = numbers[i] + '0';
        
        if (numbers[i] % 3 == 1) {
            leftHand = x;
            answer += 'L';
        }
        else if (numbers[i] % 3 == 2 || numbers[i] == 0) {
            pair <int, int> leftCoordi = getCoordi(leftHand);
            pair <int, int> rightCoordi = getCoordi(rightHand);
            pair <int, int> currentCoordi = getCoordi(x);

            int leftDistance = getDistance(leftCoordi, currentCoordi);
            int rightDistance = getDistance(rightCoordi, currentCoordi);

            if (leftDistance == rightDistance) {
                if (hand == "left") {
                    leftHand = x;
                    answer += 'L';
                }
                else {
                    rightHand = x;
                    answer += 'R';
                }
            }
            else if (leftDistance < rightDistance) {
                leftHand = x;
                answer += 'L';
            }
            else {
                rightHand = x;
                answer += 'R';
            }
        }

        else if (numbers[i] % 3 == 0) {
            rightHand = x;
            answer += 'R';
        }
    }

    return answer;
}

int main() {
    solution({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, "right");
}