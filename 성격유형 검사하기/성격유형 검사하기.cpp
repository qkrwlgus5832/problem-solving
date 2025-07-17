#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void setMap(int choice, string survey, map<string, int> *m) {
    if (choice > 4) {
        choice = choice - 4;
        string tmp = string(1, survey.at(1));
        (*m)[tmp] += choice;
    }
    else if (choice < 4) {
        choice = abs(choice - 4);
        string tmp = string(1, survey.at(0));
        (*m)[tmp] += choice;
    }
}

string getAnswer(map<string, int> m, string stanrdard1, string stardard2) {
    if (m[stanrdard1] < m[stardard2]) {
        return stardard2;
    }
    else if (m[stanrdard1] > m[stardard2]) {
        return stanrdard1;
    }
    else {
        return min(stanrdard1, stardard2);
    }
}

string solution(vector<string> survey, vector<int> choices) {
    map<string, int> m;

    string answer = "";
    for (int i = 0; i < survey.size(); i++) {
        setMap(choices[i], survey[i], &m);
    }

    answer += getAnswer(m, "R", "T");
    answer += getAnswer(m, "C", "F");
    answer += getAnswer(m, "J", "M");
    answer += getAnswer(m, "A", "N");


    return answer;
}

int main() {
    solution({ "TR", "RT", "TR" }, { 7, 1, 3 });
}