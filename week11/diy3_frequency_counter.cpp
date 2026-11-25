#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    cout << "Enter a line of words: ";
    string line;
    getline(cin, line);

    unordered_map<string, int> freq;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        freq[word]++;
    }

    if (freq.empty()) {
        cout << "No words entered.\n";
        return 0;
    }

    string bestWord;
    int bestCount = 0;
    cout << "Word frequencies:\n";
    for (const auto &p : freq) {
        cout << "  " << p.first << ": " << p.second << endl;
        if (p.second > bestCount) {
            bestCount = p.second;
            bestWord = p.first;
        }
    }
    cout << "Most frequent: " << bestWord << " (" << bestCount << " times)\n";
    return 0;
}
