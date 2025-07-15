#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool isBurger(stack <int> *burgerStack) {
    int top = burgerStack->top();
    burgerStack->pop();

    int middle = burgerStack->top();
    burgerStack->pop();

    int bottom = burgerStack->top();
    burgerStack->pop();

    if (top == 3 && middle == 2 && bottom == 1) {
        return 1;
    }
    else {
        burgerStack->push(bottom);
        burgerStack->push(middle);
        burgerStack->push(top);
        return 0;
    }

}
int solution(vector<int> ingredient) {
    stack <int> burgerStack;

    int count = 0;

    for (int i = 0; i < ingredient.size(); i++) {
        if (ingredient[i] == 1 && burgerStack.size() >= 3) {
            if (isBurger(&burgerStack)) {
                count += 1;
                continue;
            }
        } 
        burgerStack.push(ingredient[i]);
    }

    return count;
}

int main() {
    cout << solution({ 1, 3, 2, 1, 2, 1, 3, 1, 2 });
}