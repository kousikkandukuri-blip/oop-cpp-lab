#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    int vowels = 0, consonants = 0;
    for (char ch : s) {
        if (isalpha((unsigned char)ch)) {
            char c = (char)tolower((unsigned char)ch);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                ++vowels;
            else
                ++consonants;
        }
    }

    cout << "Vowels: " << vowels << "\nConsonants: " << consonants << endl;
    return 0;
}
