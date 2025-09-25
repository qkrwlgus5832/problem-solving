#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <algorithm>

using namespace std;

pair<double,double> getTimeStampFromString(string line) {
    string time = line.substr(11, 12);
    string second = line.substr(24);

    double endTime = 0;

    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    int timeSecond = stoi(time.substr(6, 2));
    int frac = stoi(time.substr(9, 3));

    endTime = frac + (timeSecond + minute * 60 + (hour * 60 * 60)) * 1000;

    second.pop_back();
   
    double processTime = stod(second) * 1000 - 1;

   
    return { endTime - processTime, endTime };
}

int solution(vector<string> lines) {
    int answer = 0;

    for (int i = 0; i < lines.size(); i++) {
        string current = lines[i];

        pair<double, double> currentTimestamp = getTimeStampFromString(current);

        int count = 1;


        if (lines.size() - i <= answer) {
            return answer;
        }

        for (int j = i + 1; j < lines.size(); j++) {
            string next = lines[j];

            pair<double, double> nextTimestmap = getTimeStampFromString(next);

            if (currentTimestamp.second + 999 >= nextTimestmap.first) {
                count++;
            }
        }

        answer = max(answer, count);
    }

    return answer;
}

int main() {
    solution({
        "2016-09-15 00:00:00.000 0.351s",
    });
}