#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int getTimeStamp(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<int> room;

    sort(book_time.begin(), book_time.end(), [](const vector<string>& a, const vector<string>& b) {
        return a[0] < b[0];
    });

    for (int i = 0; i < book_time.size(); i++) {
        int maxRoomTimeStamp = -1;
        int index = -1;
        for (int j = 0; j < room.size(); j++) {
            if (room[j] + 10 <= getTimeStamp(book_time[i][0])) {
                maxRoomTimeStamp = max(maxRoomTimeStamp, room[j]);
                index = j;
            }
        }
        if (index == -1) {
            room.push_back(getTimeStamp(book_time[i][1]));
        }
        else {
            room[index] = getTimeStamp(book_time[i][1]);
        }
    }

    return room.size();
}

int main() {
    cout << solution({ {"09:10", "10:10"},{"10:20", "12:20"} });
}