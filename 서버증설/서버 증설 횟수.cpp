#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void queuePop(queue<int>& q, int index, int k) {
  
    while (q.size()) {
        int qFront = q.front();
        if (index - qFront >= k) {
            q.pop();
        }
        else {
            break;
        }
    }
}

int solution(vector<int> players, int m, int k) {
    int answer = 0;

    queue <int> q;

    for (int i = 0; i < players.size(); i++) {
        queuePop(q, i, k);
        int needServerCount = 0;


        if (players[i] >= m) {
            needServerCount = players[i] / m;
        }

        if (q.size() >= needServerCount) {
            continue;
        }

        int additionalServer = needServerCount - q.size();
        for (int i1 = 0; i1 < additionalServer; i1++) {
            answer += 1;
            q.push(i);
        }

    }

    return answer;
}

int main() {
    cout << solution({ 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 5, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },1, 1);
}