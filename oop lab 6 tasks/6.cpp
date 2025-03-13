#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int rollNumber;
public:
    Student(string n, int r) : name(n), rollNumber(r) {}
    virtual void display() {
        cout << "Student Name: " << name << ", Roll Number: " << rollNumber << endl;
    }
};

class Marks : public Student {
protected:
    vector<int> courses;
public:
    Marks(string n, int r, vector<int> m) : Student(n, r), courses(m) {}
    void display() override {
        Student::display();
        cout << "Marks Obtained: ";
        for (int mark : courses) cout << mark << " ";
        cout << endl;
    }
};

class Result : public Marks {
public:
    Result(string n, int r, vector<int> m) : Marks(n, r, m) {}
    void display() override {
        Marks::display();
        int total = 0;
        for (int mark : courses) total += mark;
        double average = (double)total / courses.size();
        cout << "Total Marks: " << total << ", Average Marks: " << average << endl;
    }
};

int main() {
    vector<int> marks = {85, 90, 78, 88, 92};
    Result studentResult("Samana", 101, marks);
    studentResult.display();
    return 0;
}
