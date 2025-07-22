#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int result = 0;

void recursion(vector<vector<int>> dungeons, int count, int index, int ph, bool check[9]) {
    bool isAlive = false;

    for (int i = 0; i < dungeons.size(); i++) {
        if (ph >= dungeons[i][0] && check[i] == false) {
            check[i] = true;
            isAlive = true;
            recursion(dungeons, count + 1, i + 1, ph - dungeons[i][1], check);
            check[i] = false;
        }
    }

    if (isAlive == false) {
        result = max(result, count);
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    bool check[9] = { false, };
    recursion(dungeons, 0, 0, k, check);
    return result;
}

int main() {
    solution(80, { {80, 20},{50, 40},{30, 10} });
    cout << result;
}