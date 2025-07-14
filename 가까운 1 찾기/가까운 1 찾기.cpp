#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool isBurger(stack <int> *bread, stack <int> *vegi, stack<int> *meat) {
    int breadIndex = bread->top();
    int vegiIndex = vegi->top();
    int meatIndex = meat->top();

    if (breadIndex < vegiIndex && vegiIndex < meatIndex) {
        bread->pop();
        vegi->pop();
        meat->pop();
        return true;
    }

    return false;
}
int solution(vector<int> ingredient) {
    stack <int> bread;
    stack <int> vegi;
    stack <int> meat;

    int count = 0;

    for (int i = 0; i < ingredient.size(); i++) {
        if (ingredient[i] == 1) {
            if (bread.size() >= 1 && vegi.size() >= 1 && meat.size() >= 1) {
                bool result = isBurger(&bread, &vegi, &meat);
                if (result == 1) {
                    count += 1;
                    continue;
                }
            }
            bread.push(i);
        }
        else if (ingredient[i] == 2) {
            vegi.push(i);
        }
        else if (ingredient[i] == 3) {
            meat.push(i);
        }

        
    }

    return count;
}

int main() {
    cout << solution({ 2, 1, 1, 2, 3, 1, 2, 3, 1 });
}