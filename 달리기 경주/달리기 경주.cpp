#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map <string, int> m;

    for (int i = 0; i < players.size(); i++) {
        m[players[i]] = i;
    }

    for (int i = 0; i < callings.size(); i++) {
        int rank = m[callings[i]];

        string previous = players[rank - 1];
        string next = players[rank];

        players[rank] = previous;
        players[rank - 1] = next;
        m[previous] = rank;
        m[next] = rank - 1;
    }


    return players;
}

int main() {
    solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });
}