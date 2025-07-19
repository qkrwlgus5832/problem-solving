#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int getTimeStamp(string planTime) {
    int hour = stoi(planTime.substr(0, 2));
    int minute = stoi(planTime.substr(3, 2));

    return hour * 60 + minute;
}

vector<string> solution(vector<vector<string>> plans) {
    stack <pair<string, int>> st;

    vector<string> answer;

    sort(plans.begin(), plans.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[1] < b[1];
    });

    int currentSpan = 0;

    for (int i = 0; i < plans.size(); i++) {
        while (st.size()) {
            if (currentSpan > 0) {
                pair <string, int> top = st.top();
                if (top.second <= currentSpan) {
                    st.pop();
                    answer.push_back(top.first);
                    currentSpan -= top.second;
                }
                else {
                    top.second -= currentSpan;
                    st.pop();
                    st.push({ top.first, top.second });
                    currentSpan = 0;
                    break;
                }
            }
            else {
                break;
            }
        }

        if (i + 1 < plans.size()) {
            int startTimeStamp = getTimeStamp(plans[i][1]);
            int endTimeStamp = getTimeStamp(plans[i][1]) + stoi(plans[i][2]);

            int nextStartTimeStamp = getTimeStamp(plans[i + 1][1]);
            int nextEndTimeStamp = getTimeStamp(plans[i + 1][1]) + stoi(plans[i + 1][2]);

            int span = nextStartTimeStamp - startTimeStamp;

            if (span < endTimeStamp - startTimeStamp) {
                st.push({ plans[i][0], (endTimeStamp - startTimeStamp) - span });
                currentSpan = 0;
            }
            else {
                answer.push_back(plans[i][0]);
                currentSpan = nextStartTimeStamp - endTimeStamp;
            }
        }
        else {
            answer.push_back(plans[i][0]);
            while (st.size()) {
                pair<string, int> top = st.top();
                answer.push_back(top.first);
                st.pop();
            }
        }
    }
    return answer;
}


int main() {
    vector<string> result = solution({ {"aaa", "12:00", "20"},{"bbb", "12:10", "30"},{"ccc", "12:40", "10"} });
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}