#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    for (int i = 0; i < str2.size(); i++) {
        bool isPartString = true;

        for (int j = 0; j < str1.size(); j++) {
            if (str2[i + j] != str1[j]) {
                isPartString = false;
            }
        }
        if (isPartString) {
            answer = 1;
            break;
        }
    }

    return answer;
}