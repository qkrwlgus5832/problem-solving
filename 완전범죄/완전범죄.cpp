#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {

    int count = 0;
    int currentN = 0;
    int currentM = 0;

    for (int i = 0; i < info.size(); i++) {
        if (m >= currentM + info[i][1]) {
            currentM = currentM + info[i][1];
        }
        else if (n >= currentN + info[i][0]) {
            currentN = currentN + info[i][0];
            count += info[i][0];
        }
        else {
            return -1;
        }
    }
    return count;
}

int main() {
    cout << solution({ {1, 2},{2, 3},{2, 1} }, 4, 4);
}