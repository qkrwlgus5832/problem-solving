#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;


    for (int i = 0; i < s.size(); i++) {
        int oneCount = 0;
        int oneoneZeroCout = 0;
        string answerString = "";

        for (int j = 0; j < s[i].size(); j++) {

            if (s[i][j] == '0') {
                if (oneCount >= 2) {
                    oneCount -= 2;
                    oneoneZeroCout++;
                }
                else {
                    if (oneCount >= 1) {
                        answerString += '1';
                    }
                    answerString += '0';
                    oneCount = 0;
                }
            }
            else if (s[i][j] == '1') {
                oneCount++;
            }
        }

        for (int i1 = 0; i1 < oneoneZeroCout; i1++) {
            answerString += "110";
        }

        for (int i1 = 0; i1 < oneCount; i1++) {
            answerString += "1";
        }

        answer.push_back(answerString);
    }
   

    return answer;
}

int main() {
    solution({ "1110", "100111100", "0111111010" });
}