#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(const string &n = "Unknown") : name(n) {
        cout << "Person ctor: " << name << endl;
    }
};

class Student : virtual public Person {
protected:
    int rollNo;
public:
    Student(const string &n, int r) : Person(n), rollNo(r) {}
};

class Employee : virtual public Person {
protected:
    int empId;
public:
    Employee(const string &n, int id) : Person(n), empId(id) {}
};

class TA : public Student, public Employee {
    string course;
public:
    TA(const string &n, int r, int id, const string &c)
        : Person(n), Student(n, r), Employee(n, id), course(c) {}

    void show() const {
        cout << "TA " << name << " | Roll: " << rollNo
             << " | EmpID: " << empId << " | Course: " << course << endl;
    }
};

int main() {
    TA ta("Meera", 21, 504, "ECE121");
    ta.show(); // unambiguous access to Person::name
    return 0;
}
