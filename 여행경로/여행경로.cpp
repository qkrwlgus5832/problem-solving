#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

map <string, int> m;
vector<pair<string, int>> graph[10001];
map <int, bool> ticketCheck;
vector<string> result;
vector<string> answerList;

bool successFlag = false;

void recursion(string currentAirport, int count, int ticketSize) {
    int index = m[currentAirport];

    if (successFlag == true) {
        return;
    }

    if (count == ticketSize) {
        successFlag = true;
        answerList = result;
        return;
    }

    for (int i = 0; i < graph[index].size(); i++) {
        int next = m[graph[index][i].first];
        if (ticketCheck[graph[index][i].second] == false) {
            ticketCheck[graph[index][i].second] = true;
            result.push_back(graph[index][i].first);
            recursion(graph[index][i].first, count + 1, ticketSize);
            ticketCheck[graph[index][i].second] = false;
            result.pop_back();
        }
    }
}

bool compare(vector<string> v1, vector<string> v2) {
    if (v1[0] == v2[0]) {
        return v1[1] < v2[1];
    }
    return v1[0] < v2[0];
}

vector<string> solution(vector <vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), compare);

    int index = 0;
    for (int i = 0; i < tickets.size(); i++) {
        for (int j = 0; j < tickets[i].size(); j++) {
            if (m.find(tickets[i][j]) == m.end()) {
                m[tickets[i][j]] = index++;
            }
        }
    }

    for (int i = 0; i < tickets.size(); i++) {
        int index = m[tickets[i][0]];
        graph[index].push_back({ tickets[i][1], i });
    }

    result.push_back("ICN");
    recursion("ICN", 0, tickets.size());
    return answerList;
}

int main() {
    solution({ {"ICN", "BBB"},{"BBB", "ICN"},{"ICN", "AAA"} });
}