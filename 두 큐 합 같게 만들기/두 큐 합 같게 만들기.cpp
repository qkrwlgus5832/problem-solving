#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <map>

using namespace std;


int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long sum = 0;

    long long sum1 = 0;

    long long sum2 = 0;

    map<long long, long long> m;

    for (int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        sum += queue1[i];
        m[{queue1[i]}] = i;
    }

    for (int i = 0; i < queue2.size(); i++) {
        sum2 += queue2[i];
        sum += queue2[i];
        m[{queue2[i]}] = i;
    }

    if (sum % 2 != 0) {
        return -1;
    }

    deque<long long> deque1(queue1.begin(), queue1.end());
    deque<long long> deque2(queue2.begin(), queue2.end());

    bool check[300001] = { false, };

    
    while (1) {
        if (deque1.size() == 0 || deque2.size() == 0) {
            return -1;
        }


        if (sum1 == (sum / 2)) {
            return answer;
        }
       
        else if (sum1 < (sum / 2)) {
            long long front = deque2.front();
            deque2.pop_front();
            deque1.push_back(front);
            sum1 += front;
            answer++;
        }
        else {
            long long front = deque1.front();
            deque1.pop_front();
            deque2.push_back(front);
            sum1 -= front;
            answer++;
        }

        if (answer > (queue1.size() + queue2.size()) * 4) {
            return -1;
        }

        if (deque1.size() == 1) {
            if (check[m[deque1[0]]] == true) {
                return -1;
            }
            else {
                check[m[deque1[0]]] = true;
            }
        }
        else if (deque2.size() == 1) {
            if (check[m[deque2[0]]] == true) {
                return -1;
            }
            else {
                check[m[deque2[0]]] = true;
            }
        }
    }

    return answer;
}

int main() {
    cout << solution({ 10, 5, 1 }, { 2, 2, 2 });
    
}