#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int answer = 0;

bool isAnswer(vector<int> v, vector<vector<int>> q, vector<int> ans) {
    for (int i = 0; i < q.size(); i++) {
        int count = 0;
        for (int j = 0; j < v.size(); j++) {
            for (int i1 = 0; i1 < q[i].size(); i1++) {
                if (v[j] == q[i][i1]) {
                    count++;
                }
            }
        }
        if (count != ans[i]) {
            return false;
        }
    }
   
    return true;
}

void recursion(bool check[31], int count, vector<int> v, vector<vector<int>> q, vector<int> ans, vector<int> origin, int index) {
    if (count == 5) {
        if (isAnswer(v, q, ans)) {
            answer++;
        }
        return;
    }

    for (int i1 = index; i1 < origin.size(); i1++) {
        if (check[origin[i1]] == false) {
            check[origin[i1]] = true;
            v.push_back(origin[i1]);
            recursion(check, count + 1, v, q, ans, origin, i1 + 1);
            v.pop_back();
            check[origin[i1]] = false;
        }
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    bool check[31] = { false, };

    set<int> s;

    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    vector<int> v(s.begin(), s.end());

    recursion(check, 0, vector<int>(), q, ans, v, 0);
    return answer;
}

int main() {
    solution(15, { {1, 2, 3, 4, 5},{6, 7, 8, 9, 10},{3, 7, 8, 9, 10},{2, 5, 7, 9, 10},{3, 4, 5, 6, 7} }, { 2, 3, 4, 3, 3 });
    cout << answer;
}