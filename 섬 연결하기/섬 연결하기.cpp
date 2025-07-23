#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <limits.h>
using namespace std;

class edge {
public:
    int number;
    int cost;

    edge(int number, int cost) {
        this->number = number;
        this->cost = cost;
    }
};
vector <edge> v[101];
set <int> s;


bool compare(vector <int>& a, vector <int>& b) {
    return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {
    sort(costs.begin(), costs.end(), compare);


    for (vector <int> cost : costs) {
        v[cost[0]].push_back(edge(cost[1], cost[2]));
        v[cost[1]].push_back(edge(cost[0], cost[2]));
    }

    s.insert(costs[0][0]);
    s.insert(costs[0][1]);
    int answer = costs[0][2];

    while (1) {
        int minValue = INT_MAX;
        int minIndex = -1;

        for (auto tmp : s) {
            for (int i = 0; i < v[tmp].size(); i++) {
                if (s.find(v[tmp][i].number) == s.end()) {
                    if (v[tmp][i].cost < minValue) {
                        minValue = v[tmp][i].cost;
                        minIndex = v[tmp][i].number;
                    }
                }
            }
        }
        s.insert(minIndex);
        answer += minValue;
        if (s.size() == n)
            break;
    }


    return answer;
}