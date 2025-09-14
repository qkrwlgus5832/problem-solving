#include <string>
#include <vector>

using namespace std;

int cookieSum[200001];

int solution(vector<int> cookie) {
    int answer = 0;

    for (int i = 0; i < cookie.size() - 1; i++) {
        cookie[i + 1] = cookie[i] + cookie[i + 1];
    }

    for (int i = 0; i < cookie.size(); i++) {
        cookieSum[cookie[i]]++;
    }

    for (int i = 0; i < cookie.size(); i++) {
        for (int j = 0; j < i; j++) {
            int span = cookie[i] - cookie[j];
            if (cookieSum[span + cookie[i]] > 0) {
                answer = max(answer, span);
            }
        }

        int span = cookie[i];
        if (cookieSum[span + cookie[i]] > 0) {
            answer = max(answer, span);
        }
    }


    return answer;
}

int main() {
    vector<int> cookie;
    for (int i = 0; i < 2000; i++) {
        cookie.push_back(500);
    }

    solution(cookie);
}