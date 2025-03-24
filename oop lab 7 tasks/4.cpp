#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;

public:
    Person(string n, string i, string a, string p, string e) {
        name = n;
        id = i;
        address = a;
        phoneNumber = p;
        email = e;
    }

    virtual void displayInfo() const {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address << "\nPhone: " << phoneNumber << "\nEmail: " << email << "\n";
    }
};

class Student : public Person {
private:
    vector<string> coursesEnrolled;
    double gpa;
    int enrollmentYear;

public:
    Student(string n, string i, string a, string p, string e, double g, int year)
        : Person(n, i, a, p, e) {
        gpa = g;
        enrollmentYear = year;
    }

    void enrollCourse(string course) {
        coursesEnrolled.push_back(course);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "GPA: " << gpa << "\nEnrollment Year: " << enrollmentYear << "\nCourses: ";
        for (const string &course : coursesEnrolled) {
            cout << course << " ";
        }
        cout << "\n";
    }
};

class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    double salary;

public:
    Professor(string n, string i, string a, string p, string e, string dept, double s)
        : Person(n, i, a, p, e) {
        department = dept;
        salary = s;
    }

    void addCourse(string course) {
        coursesTaught.push_back(course);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: " << salary << "\nCourses Taught: ";
        for (const string &course : coursesTaught) {
            cout << course << " ";
        }
        cout << "\n";
    }
};

class Staff : public Person {
private:
    string department, position;
    double salary;

public:
    Staff(string n, string i, string a, string p, string e, string dept, string pos, double s)
        : Person(n, i, a, p, e) {
        department = dept;
        position = pos;
        salary = s;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: " << salary << "\n";
    }
};

class Course {
private:
    string courseId, courseName, instructor, schedule;
    int credits;
    vector<string> studentsEnrolled;

public:
    Course(string id, string name, int c, string instr, string sched) {
        courseId = id;
        courseName = name;
        credits = c;
        instructor = instr;
        schedule = sched;
    }

    void registerStudent(string studentId) {
        studentsEnrolled.push_back(studentId);
    }

    void displayCourseInfo() const {
        cout << "Course ID: " << courseId << "\nCourse Name: " << courseName << "\nCredits: " << credits << "\nInstructor: " << instructor << "\nSchedule: " << schedule << "\nStudents Enrolled: ";
        for (const string &student : studentsEnrolled) {
            cout << student << " ";
        }
        cout << "\n";
    }
};

int main() {
    Student s1("Ali Khan", "S1001", "Lahore, Pakistan", "0300-1234567", "ali.khan@nu.edu.pk", 3.8, 2021);
    s1.enrollCourse("CS101");
    s1.enrollCourse("Math201");
    Professor p1("Dr. Ahmed", "P2001", "Islamabad, Pakistan", "0321-9876543", "ahmed@nu.edu.pk", "Computer Science", 150000);
    p1.addCourse("CS101");
    p1.addCourse("AI202");
    Staff st1("Hassan Raza", "ST3001", "Karachi, Pakistan", "0345-1122334", "hassan.raza@nu.edu.pk", "Administration", "Manager", 80000);
    Course c1("CS101", "Intro to Computer Science", 3, "Dr. Ahmed", "MWF 10:00-11:00");
    c1.registerStudent("S1001");
    s1.displayInfo();
    p1.displayInfo();
    st1.displayInfo();
    c1.displayCourseInfo();

    return 0;
}
