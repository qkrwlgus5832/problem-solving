#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool recursion(string bablling, int index, string previous) {
    if (index == bablling.size()) {
        return true;
    }
    if (bablling.substr(index, 3) == "aya" && previous != "aya") {
        return recursion(bablling, index + 3, "aya");
    }
    else if (bablling.substr(index, 2) == "ye" && previous != "ye") {
        return recursion(bablling, index + 2, "ye");
    }
    else if (bablling.substr(index, 3) == "woo" && previous != "woo") {
        return recursion(bablling, index + 3, "woo");
    }
    else if (bablling.substr(index, 2) == "ma" && previous != "ma") {
        return recursion(bablling, index + 2, "ma");
    }
    return false;
}

int solution(vector<string> babbling) {
    int answer = 0;

    for (int i = 0; i < babbling.size(); i++) {
        answer += recursion(babbling[i], 0, "");
    }
    
    return answer;
}

int main() {
    cout << solution({ "aya", "yee", "u", "maa" });
}