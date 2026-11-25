#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Create sample in.txt if not present
    ifstream check("in.txt");
    if (!check) {
        ofstream sample("in.txt");
        sample << "First line\nSecond line\nThird line\n";
    }
    check.close();

    ifstream in("in.txt");
    ofstream out("out.txt");
    if (!in || !out) {
        cerr << "File open failed\n";
        return 1;
    }

    string line;
    int lineNo = 1;
    while (getline(in, line)) {
        out << lineNo++ << ": " << line << "\n";
    }
    cout << "Copied " << (lineNo - 1) << " line(s) to out.txt\n";
    return 0;
}
