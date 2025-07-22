#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> tangerineMap;
    
    vector<pair<int, int>> v;

    for (int i = 0; i < tangerine.size(); i++) {
        tangerineMap[tangerine[i]] += 1;
    }

    for (auto iter : tangerineMap) {
        v.push_back({ iter.first, iter.second });
    }

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    for (int i = 0; i < v.size(); i++) {
        k -= v[i].second;
        answer++;

        if (k <= 0) {
            return answer;
        }
    }

    return answer;
}

int main() {
    cout << solution(2, { 1, 1, 1, 1, 2, 2, 2, 3 });
}