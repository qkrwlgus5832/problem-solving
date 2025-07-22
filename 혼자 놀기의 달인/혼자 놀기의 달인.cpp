#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;

    bool isOpend[101] = {false,};

    vector<vector<int>> group;

    int groupIndex = 0;
    int currentIndex = 0;


    while (1) {
        bool isEnd = true;

        while(1) {
            int number = cards[currentIndex];
            if (isOpend[number] == true) {
                for (int i = 0; i < cards.size(); i++) {
                    if (isOpend[cards[i]] == false) {
                        currentIndex = i;
                        isEnd = false;
                        break;
                    }
                }
                break;
            }

            isOpend[number] = true;

            if (group.size() == groupIndex) {
                vector<int> groupCards = { number };
                group.push_back(groupCards);
            }
            else {
                group[groupIndex].push_back(number);
            }
            
            currentIndex = number - 1;
        }
        if (isEnd) {
            break;
        }
        groupIndex++;
    }

    vector<int> resultCount;

    for (int i = 0; i < group.size(); i++) {
        resultCount.push_back(group[i].size());
    }

    sort(resultCount.begin(), resultCount.end(), greater<int>());

    if(resultCount.size() == 1) {
        return 0;
    }
    else {
        return resultCount[0] * resultCount[1];
    }
}

int main() {
    solution({ 8,6,3,7,2,5,1,4 });
}