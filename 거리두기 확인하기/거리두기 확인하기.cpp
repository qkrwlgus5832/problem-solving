#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int BFS(int i, int j, int waitingRoomIndex, vector<vector<string>> places) {
    queue<tuple<int, int, int>> q;
    q.push({ i, j, 0 });

    bool check[6][6] = { false, };
    check[i][j] = true;

    int dir[4][2] = { {-1, 0}, {1,0}, {0, -1}, {0, 1} };

    while (q.size()) {
        tuple<int, int, int> front = q.front();

        q.pop();

        for (int i1 = 0; i1 < 4; i1++) {
            int ni = get<0>(front) + dir[i1][0];
            int nj = get<1>(front) + dir[i1][1];
            int distance = get<2>(front);

            if (ni < 0 || nj < 0 || ni >= places[waitingRoomIndex].size() || nj >= places[waitingRoomIndex][0].size()) {
                continue;
            }

          
            if (check[ni][nj] == false && places[waitingRoomIndex][ni][nj] == 'O') {
                check[ni][nj] = true;
                q.push({ ni, nj, distance + 1 });
            }
            else if (check[ni][nj] == false && places[waitingRoomIndex][ni][nj] == 'P' && distance <= 1) {
                return -1;
            }

        }
    }

    return 1;
}

bool check(int i, int j, int waitingRoomIndex, vector<vector<string>> places) {
    if (BFS(i, j, waitingRoomIndex, places) == -1) {
        return false;
   }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); i++) {
        bool isSuccess = true;

        for (int i1 = 0; i1 < places[i].size(); i1++) {
            for (int i2 = 0; i2 < places[i][i1].size(); i2++) {
                if (places[i][i1][i2] == 'P') {
                    int result = check(i1, i2, i, places);
                    if (result == 0) {
                        isSuccess = false;
                    }
                }
            }
        }

        answer.push_back(isSuccess);
    }
    
    return answer;

}

int main() {
    solution({ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},{"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} });
}