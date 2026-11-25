#include <iostream>
using namespace std;

template <typename T>
void swapVals(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T findMax(const T arr[], int n) {
    T mx = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > mx) mx = arr[i];
    }
    return mx;
}

int main() {
    int a = 10, b = 25;
    swapVals(a, b);
    cout << "Swapped ints: a=" << a << ", b=" << b << endl;

    double x = 3.14, y = 9.81;
    swapVals(x, y);
    cout << "Swapped doubles: x=" << x << ", y=" << y << endl;

    int iArr[] = {4, 19, 7, 12};
    double dArr[] = {2.5, 8.75, 4.2};
    cout << "Max int: " << findMax(iArr, 4) << endl;
    cout << "Max double: " << findMax(dArr, 3) << endl;
    return 0;
}
