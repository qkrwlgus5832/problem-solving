#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


int solution(vector<vector<int>> scores) {
    int answer = 0;

    pair<int, int> wanhoScore = { scores[0][0], scores[0][1] };

    int dp[100001] = { 0, };

    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });

    int maxFirstScore = scores[0][0];
    dp[0] = scores[0][0];

    map<int, int> ranks;

    for (int i = 1; i < scores.size(); i++) {
        if (scores[i - 1][1] > scores[i][1]) {
            dp[i] = maxFirstScore;
        }
        else {
            dp[i] = dp[i - 1];
        }
        maxFirstScore = max(scores[i][0], maxFirstScore);
    }

    for (int i = 0; i < scores.size(); i++) {
        if (dp[i] > scores[i][0]) {
            if (scores[i][0] == wanhoScore.first && scores[i][1] == wanhoScore.second) {
                return -1;
            }
            continue;
        }
        else {
            ranks[scores[i][0] + scores[i][1]]++;
        }
    }

    set <int> s;

    for (auto rank : ranks) {
        s.insert(rank.first);
    }

    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (*it == wanhoScore.first + wanhoScore.second) {
            return answer + 1;
        }
        else {
            answer += ranks[*it];
        }
    }

    return answer;
}

int main() {
    cout << solution({ {2, 2},{1, 4},{3, 2},{3, 2},{2, 1} });
}