#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        pair <int, int> range = { commands[i][0], commands[i][1] };
        
        set<int> s;

        for (int j = range.first - 1; j < range.second; j++) {
            s.insert(array[j]);
        }

        auto it = s.begin();
        advance(it, commands[i][2] - 1);
        answer.push_back(*it);
    }
    return answer;
}

int main() {
    solution({ 1, 5, 2, 6, 3, 7, 4 }, { { 2, 5, 3},{4, 4, 1},{1, 7, 3} });
}