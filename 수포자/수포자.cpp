#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> first = { 1,2,3,4,5 };
    vector<int> second = { 2, 1, 2, 3, 2, 4, 2,5 };
    vector<int> third = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int firstIndex = 0;
    int secondIndex = 0;
    int thirdIndex = 0;

    int firstScore = 0;
    int secondScore = 0;
    int thirdScore = 0;

    for (int i = 0; i < answers.size(); i++) {
        firstIndex = i % first.size();
        secondIndex = i % second.size();
        thirdIndex = i % third.size();

        if (first[firstIndex] == answers[i]) {
            firstScore++;
        }
        if (second[secondIndex] == answers[i]) {
            secondScore++;
        }
        if (third[thirdIndex] == answers[i]) {
            thirdScore++;
        }
    }

    int maxScore = max(firstScore, secondScore);
    maxScore = max(maxScore, thirdScore);

    if (firstScore == maxScore) {
        answer.push_back(1);
    }
    if (secondScore == maxScore) {
        answer.push_back(2);
    }
    if (thirdScore == maxScore) {
        answer.push_back(3);
    }
    
    return answer;
}

int main() {
    solution({ 1,2,3,4,5 });
}