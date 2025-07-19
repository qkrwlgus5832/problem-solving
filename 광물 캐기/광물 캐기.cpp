#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int result = -1;


pair<int, int> getPhSum(vector<string> minerals, int index, string mineral, map<pair<string, string>, int> m) {
    int ph = 0;
    int count = 0;
    for (int i = index; i < index + 5; i++) {
        if (i < minerals.size()) {
            ph += m[{mineral, minerals[i]}];
            count++;
        }
    }
    return { ph, count };
}

void recursion(vector<int> picks, vector<string> minerals, int index, map<pair<string ,string>, int> m, int ph) {
    if (index >= minerals.size()) {
        if (result == -1) {
            result = ph;
        }
        else {
            result = min(result, ph);
        }
        return;
    }

    bool isEmpty = true;

    for (int i = 0; i < picks.size(); i++) {
        if (picks[i] > 0) {
            if (i == 0) {
                pair <int, int> phAndCount = getPhSum(minerals, index, "diamond", m);
                picks[i]--;
                recursion(picks, minerals, index + phAndCount.second, m, ph + phAndCount.first);
                picks[i]++;
            }
            else if (i == 1) {
                pair <int, int> phAndCount = getPhSum(minerals, index, "iron", m);
                picks[i]--;
                recursion(picks, minerals, index + phAndCount.second , m, ph + phAndCount.first);
                picks[i]++;
            }
            else if (i == 2) {
                pair <int, int> phAndCount = getPhSum(minerals, index, "stone", m);
                picks[i]--;
                recursion(picks, minerals, index + phAndCount.second, m, ph + phAndCount.first);
                picks[i]++;

            }
            isEmpty = false;
        }
    }

    if (isEmpty) {
        if (result == -1) {
            result = ph;
        }
        else {
            result = min(result, ph);
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    map <pair<string, string>, int> m;

    m[{"diamond", "diamond"}] = 1;
    m[{"iron", "diamond"}] = 5;
    m[{"stone", "diamond"}] = 25;
    m[{"diamond", "iron"}] = 1;
    m[{"iron", "iron"}] = 1;
    m[{"stone", "iron"}] = 5;
    m[{"diamond", "stone"}] = 1;
    m[{"iron", "stone"}] = 1;
    m[{"stone", "stone"}] = 1;


    recursion(picks, minerals, 0, m, 0);
    return answer;
}


int main() {
    solution({ 1, 3, 2 }, { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" });
    cout << result;
}