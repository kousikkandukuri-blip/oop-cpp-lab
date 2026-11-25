#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int marks = 0;
};

int main() {
    ofstream out("records.txt");
    if (!out) {
        cerr << "Cannot write records.txt\n";
        return 1;
    }
    out << "Asha 88\nRavi 95\nMeera 91\nKiran 84\n";
    out.close();

    ifstream in("records.txt");
    if (!in) {
        cerr << "Cannot read records.txt\n";
        return 1;
    }

    const int MAX = 100;
    Student students[MAX];
    int count = 0;

    while (count < MAX && (in >> students[count].name >> students[count].marks)) {
        ++count;
    }

    if (count == 0) {
        cout << "No student records found.\n";
        return 0;
    }

    int topIdx = 0;
    for (int i = 1; i < count; ++i) {
        if (students[i].marks > students[topIdx].marks) {
            topIdx = i;
        }
    }

    cout << "Topper: " << students[topIdx].name
         << " (" << students[topIdx].marks << " marks)\n";
    return 0;
}
