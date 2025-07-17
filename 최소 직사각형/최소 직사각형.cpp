#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    vector<int> v;
    vector<int> v2;

    for (int i = 0; i < sizes.size(); i++) {
        v.push_back(min(sizes[i][0], sizes[i][1]));
        v2.push_back(max(sizes[i][0], sizes[i][1]));
    }

    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());

    return v[v.size() - 1] * v2[v2.size() - 1];
}