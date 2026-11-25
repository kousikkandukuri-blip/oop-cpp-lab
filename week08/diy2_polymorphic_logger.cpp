#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
public:
    virtual void write(const string &msg) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(const string &msg) override {
        cout << "[CONSOLE] " << msg << endl;
    }
};

class FileLogger : public Logger {
    string filename;
public:
    FileLogger(const string &fn) : filename(fn) {}
    void write(const string &msg) override {
        ofstream out(filename, ios::app);
        if (out) {
            out << "[FILE] " << msg << "\n";
        }
    }
};

int main() {
    int choice = 1;
    cout << "Choose logger (1=Console, 2=File): ";
    if (!(cin >> choice)) choice = 1;

    Logger *logger = nullptr;
    if (choice == 2)
        logger = new FileLogger("app.log");
    else
        logger = new ConsoleLogger();

    logger->write("Verification started");
    logger->write("All checks passed");

    if (choice == 2) cout << "Wrote logs to app.log\n";
    delete logger;
    return 0;
}
