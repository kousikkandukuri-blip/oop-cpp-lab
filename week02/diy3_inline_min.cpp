#include <iostream>
using namespace std;

inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    cout << "minVal(12, 7) = " << minVal(12, 7) << endl;
    cout << "minVal(12, 7, 19) = " << minVal(12, 7, 19) << endl;
    return 0;
}
