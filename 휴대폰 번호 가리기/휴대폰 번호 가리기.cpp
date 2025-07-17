#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    for (int i = 0; i < phone_number.size(); i++) {
        if (i <= phone_number.size() - 1 && i >= phone_number.size() - 3) {
            continue;
        }
        phone_number[i] = '*';
    }

    return phone_number;
}