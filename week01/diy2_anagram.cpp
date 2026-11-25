#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string a, b;
    cout << "Enter two words: ";
    cin >> a >> b;

    if (a.size() != b.size()) {
        cout << "Not anagrams\n";
        return 0;
    }

    int freq[256] = {0};
    for (size_t i = 0; i < a.size(); ++i) {
        freq[(unsigned char)tolower((unsigned char)a[i])]++;
        freq[(unsigned char)tolower((unsigned char)b[i])]--;
    }

    bool ok = true;
    for (int f : freq) {
        if (f != 0) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Anagrams" : "Not anagrams") << endl;
    return 0;
}
