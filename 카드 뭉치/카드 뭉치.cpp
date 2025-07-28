#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";

    int card1Index = 0;
    int card2Index = 0;

    int goalIndex = 0;

    while (1) {
        if (goalIndex == goal.size()) {
            break;
        }
        if (cards1[card1Index] != goal[goalIndex] && cards2[card2Index] != goal[goalIndex]) {
            return "No";
        }
        else if (cards1[card1Index] == goal[goalIndex]) {
            card1Index++;
            goalIndex++;
        }
        else if (cards2[card2Index] == goal[goalIndex]) {
            card2Index++;
            goalIndex++;
        }
    }

    return "Yes";
}

int main() {
    cout << solution({ "i", "drink", "water" }, { "want", "to" }, { "i", "want", "to", "drink" ,"water" });
}