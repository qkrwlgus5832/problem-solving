#include <string>
#include <vector>

using namespace std;

int getStanrdard(int x) {
    int standard = 1;

    while (1) {
        if (x >= standard && x < standard * 2) {
            return standard;
        }
        standard *= 2;
    }
}

string getBinaryNumber(int x, int standard) {
    string binary = "";

    while (x != 0 || standard != 0) {
        if (x >= standard) {
            x = x - standard;
            binary += "1";
        }
        else {
            binary += "0";
        }

        standard /= 2;
    }

    return binary;

}
vector<int> solution(string s) {
    vector<int> answer;

    int length = 0;
    int zeroCount = 0;

    int count = 0;
    while (1) {
        if (s == "1") {
            break;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                length++;
            }
            else {
                zeroCount++;
            }
        }

        s = getBinaryNumber(length, getStanrdard(length));

        count++;
        length = 0;
    }

    return { count, zeroCount };
}

int main() {
    solution("1111111");
}