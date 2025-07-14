#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b, int c) {
    if (a != b && b != c && a != c) {
        return a + b + c;
    }
    else if (a == b && b != c) {
        return (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2));
    }
    else if (a == c && c != b) {
        return (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2));
    } 
    else if (b == c && c != a) {
        return (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2));
    }
    else if (a == b && b == c && a == c) {
        return (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2)) * (pow(a, 3) + pow(b, 3) + pow(c, 3));
    }
}