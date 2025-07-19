#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;


bool check[101][101] = { false, };
int dir[4][2] = { {-1,0}, {1,0}, {0, -1}, {0, 1} };

int BFS(vector<string> maps, int i, int j) {
    queue <pair<int, int>> q;

    int sum = (maps[i][j] - '0');

    check[i][j] = true;
    q.push({ i,j });

    while (q.size()) {
        pair<int, int> front = q.front();
        q.pop();

        for (int i1 = 0; i1 < 4; i1++) {
            int x = front.first + dir[i1][0];
            int y = front.second + dir[i1][1];

            if (x < 0 || y < 0 || x >= maps.size() || y >= maps[0].size()) {
                continue;
            }

            if (check[x][y] == false && maps[x][y] != 'X') {
                check[x][y] = true;
                sum += (maps[x][y] -'0');
                q.push({ x,y });
            }
        }
    }
    return sum;
}


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    queue<int> q;
    
    int count = 0;

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (check[i][j] == false && maps[i][j] != 'X') {
                count++;
                answer.push_back(BFS(maps, i, j));
            }
        }
    }

    sort(answer.begin(), answer.end());

    if (count == 0) {
        return { -1 };
    }

    return answer;

}

int main() {
    vector<int> result = solution({ "X5XX5X", "111111", "XXXXXX", "111111" });

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}