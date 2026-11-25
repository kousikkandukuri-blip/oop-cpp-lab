#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line;
    cout << "Enter a sentence: ";
    getline(cin, line);

    stringstream ss(line);
    vector<string> words;
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    for (int i = (int)words.size() - 1; i >= 0; --i) {
        cout << words[i] << (i > 0 ? " " : "");
    }
    cout << endl;
    return 0;
}
