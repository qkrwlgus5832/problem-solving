#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
   
    int currentPaint = 0;

    for (int i = 0; i < section.size(); i++) {
        if (currentPaint < section[i]) {
            currentPaint = section[i] + (m - 1);
            answer += 1;
        }
    }

    return answer;
}