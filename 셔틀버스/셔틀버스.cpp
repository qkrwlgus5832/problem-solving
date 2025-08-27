#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

int getTimeStamp(string timetable) {
    string hour = timetable.substr(0, 2);
    string minute = timetable.substr(3, 5);

    return stoi(hour) * 60 + stoi(minute);
}

string getTimeTable(int timestamp) {
    int hour = timestamp / 60;
    int minute = timestamp % 60;

    string stringHour = to_string(hour);
    string stringMinute = to_string(minute);

    if (hour >= 0 && hour <= 9) {
        stringHour = "0" + stringHour;
    }
    
    if (minute >= 0 && minute <= 9) {
        stringMinute = "0" + stringMinute;
    }

    return stringHour + ":" + stringMinute;
}

string solution(int n, int t, int m, vector<string> timetable) {
    sort(timetable.begin(), timetable.end());

    int standard = 60 * 9;
       
    stack<int> st[11];

    int nIndex = 0;
    int mIndex = 0;
    int timeTableIndex = 0;

    while (1) {
        if (timeTableIndex >= timetable.size()) {
            break;
        }

        int timeStamp = getTimeStamp(timetable[timeTableIndex]);
        
        if (timeStamp <= standard + (nIndex * t) && mIndex < m) {
            st[nIndex].push(timeStamp);
            mIndex++;
            timeTableIndex++;
        }
        else {
            if (nIndex == n - 1) {
                break;
            }

            nIndex++;
            mIndex = 0;
        }

    }

    int result;

    if (mIndex < m) {
        result = standard + ((n-1)*t);
    }
    else {
        result = st[nIndex].top() - 1;
    }

    return getTimeTable(result);
}

int main() {
    cout << solution(1, 1 , 1, {"23:59"});
}