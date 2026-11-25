#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<string, int>> items = {
        {"Alice", 88}, {"Bob", 72}, {"Charlie", 95}, {"Diana", 81}
    };

    sort(items.begin(), items.end(),
         [](const pair<string, int> &a, const pair<string, int> &b) {
             return a.second < b.second;
         });

    cout << "Sorted ascending by score:\n";
    for (const auto &p : items) {
        cout << p.first << " -> " << p.second << endl;
    }
    return 0;
}
