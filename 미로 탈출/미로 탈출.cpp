#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;


int BFS(int startX, int startY, bool check[101][101][2], vector<string> maps) {
    queue <tuple<int, int, bool>> q;
   
    int dir[4][2] = { {-1,0}, {1,0}, {0, -1}, {0, 1} };

    q.push(tuple<int, int, bool>(startX, startY, false));

    int depth = 0;

    while (q.size()) {
        int qSize = q.size();
        for (int i1 = 0; i1 < qSize; i1++) {
            tuple<int, int, bool> front = q.front();
            int x = get<0>(front);
            int y = get<1>(front);

            q.pop();

            for (int i = 0; i < 4; i++) {
                int x1 = x + dir[i][0];
                int y1 = y + dir[i][1];

                if (x1 < 0 || y1 < 0 || x1 >= maps.size() || y1 >= maps[0].size()) {
                    continue;
                }

                bool isLevered = get<2>(front);

                if (maps[x1][y1] == 'L') {
                    isLevered = true;
                }

                else if (maps[x1][y1] == 'E' && isLevered) {
                    return depth + 1;
                }

                if (check[x1][y1][isLevered] == false && maps[x1][y1] != 'X') {
                    check[x1][y1][isLevered] = true;
                    q.push(tuple<int, int, bool>(x1, y1, isLevered));
                }
            }
        }

        depth++;
  
    }
    return -1;
}

int solution(vector<string> maps) {
    bool check[101][101][2] = { false, };

    int startX = -1;
    int startY = -1;

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0;j < maps[i].size(); j++) {
            if (maps[i][j] == 'S') {
                startX = i;
                startY = j;
            }
        }
    }


    return BFS(startX, startY, check, maps);
}

int main() {
    cout << solution({ "LOOXS", "OOOOX", "OOOOO", "OOOOO", "EOOOO" });
}