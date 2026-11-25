#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

int main() {
    // Ensure nums.txt exists with sample data if not already present
    ifstream check("nums.txt");
    if (!check) {
        ofstream sample("nums.txt");
        sample << "12 45 7 89 23 4 56\n";
    }
    check.close();

    ifstream in("nums.txt");
    if (!in) {
        cerr << "Cannot open nums.txt\n";
        return 1;
    }

    int x, count = 0;
    long long sum = 0;
    int mn = numeric_limits<int>::max();
    int mx = numeric_limits<int>::min();

    while (in >> x) {
        ++count;
        sum += x;
        if (x < mn) mn = x;
        if (x > mx) mx = x;
    }

    if (count == 0) {
        cout << "No numbers found in nums.txt\n";
    } else {
        cout << "Count: " << count
             << "\nSum: " << sum
             << "\nMin: " << mn
             << "\nMax: " << mx << endl;
    }
    return 0;
}
