#include <iostream>

using namespace std;

class Student {
    const string roll_no;

public:
    Student(string roll) : roll_no(roll) {}

    void display() {
        cout << "Student Roll Number: " << roll_no << endl;
    }
};

int main() {
    string roll;
    cout << "Enter student roll number: ";
    cin >> roll;

    Student s(roll);
    s.display();

    return 0;
}
