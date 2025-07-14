#include <string>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool isHoliday(int startday, int plusday) {
    if ((startday + plusday) % 7 == 6 || (startday + plusday) % 7 == 0) {
        return true;
    }
    return false;
}
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;

    for (int i = 0; i < schedules.size(); i++) {
        string schedulsString = to_string(schedules[i]);

        string hour;
        string minute;
        if (schedulsString.length() == 3) {
            hour = schedulsString.substr(0, 1);
            minute = schedulsString.substr(1, 3);
        }
        else {
            hour = schedulsString.substr(0, 2);
            minute = schedulsString.substr(2, 4);
        }

        if (stoi(minute) + 10 >= 60) {
            hour = to_string(stoi(hour) + 1);
        }

        minute = to_string((stoi(minute) + 10) % 60);

        bool isSuccess = true;

        for (int j = 0; j < timelogs[i].size(); j++) {
            if (isHoliday(startday, i)) {
                continue;
            }
            if (timelogs[i][j] > stoi(hour) * 100 + stoi(minute)) {
                isSuccess = false;
            }
        }

        if (isSuccess) {
            answer = answer + 1;
            cout << i;
        }
     
    }
    return answer;
}

int main() {
    solution(
        { 700, 800, 1100 },
        { {710, 2359, 1050, 700, 650, 631, 659},{800, 801, 805, 800, 759, 810, 809},{1105, 1001, 1002, 600, 1059, 1001, 1100} },
        5
    );
}