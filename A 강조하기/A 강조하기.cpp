#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string myString) {
    string answer = "";

    for (int i = 0; i < myString.length(); i++) {
        if (myString[i] == 'a') {
            answer += 'A';
        }
        else if (myString[i] > 'A' && myString[i] <= 'Z') {
            answer += ((myString[i] - 'A') + 'a');
        }
        else {
            answer += myString[i];
        }
   }
    return answer;
}

int main() {
    cout << solution("abstract algebra");
}