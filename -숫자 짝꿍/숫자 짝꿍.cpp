#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    map<int, int> xMap;
    map<int, int> yMap;

    map<int, int> commonMap;

    for (int i = 0; i < X.size(); i++) {
        xMap[X[i] - '0']++;
    }

    for (int i = 0; i < Y.size(); i++) {
        yMap[Y[i] - '0']++;
    }

    for (int i = 9; i >= 0; i--) {
        if (xMap[i] > 0 && yMap[i] > 0) {
            commonMap[i] = min(xMap[i], yMap[i]);
        }
    }

    for (int i = 9; i >= 1; i--) {
        for (int j = 0; j < commonMap[i]; j++) {
            answer += (i + '0');
        }
    }
    
    if (answer.size() == 0 && commonMap[0] > 0) {
        return "0";
    }

    else if (commonMap[0] > 0) {
        for (int j = 0; j < commonMap[0]; j++) {
            answer += '0';
        }
    }

    if (answer.size() == 0) {
        return "-1";
    }

    return answer;
}

int main() {
    cout << solution("5525", "1255");
}