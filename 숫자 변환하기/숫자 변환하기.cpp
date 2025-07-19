#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


int BFS(int x, int y, int n) {
    queue<int> q;
    
    int depth = 0;

    q.push(x);
    bool check[1000001] = { false, };

    while (q.size()) {
        int qSize = q.size();
        
        for (int i = 0; i < qSize; i++) {
            int front = q.front();

            if (y == front) {
                return depth;
            }
            
            q.pop();

            if (front + n <= y && check[front + n] == false) {
                check[front + n] = true;
                q.push(front + n);
            }

            if (front * 2 <= y && check[front * 2] == false) {
                check[front * 2] = true;
                q.push(front * 2);
            }

            if (front * 3 <= y && check[front * 3] == false) {
                check[front * 3] = true;
                q.push(front * 3);
            }
        }
        
        depth++;
    }

    return -1;
}
int solution(int x, int y, int n) {
    return BFS(x, y, n);
}

int main() {
    cout << solution(10, 40, 5);
}