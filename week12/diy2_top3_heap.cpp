#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    priority_queue<int> pq;
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        pq.push(val);
    }

    cout << "Top 3 largest: ";
    for (int k = 0; k < 3 && !pq.empty(); ++k) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    return 0;
}
