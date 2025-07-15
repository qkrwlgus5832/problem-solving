#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }

    sort(answer.begin(), answer.end());
    auto v = unique(answer.begin(), answer.end());
    
    answer.erase(v, answer.end());
   
    return answer;
}

int main() {
    solution({ 2,1,3,4,1 });
}