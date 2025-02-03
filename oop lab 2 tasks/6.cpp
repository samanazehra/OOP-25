#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Subject {
    string subject_name;
};

struct Student {
    int id;
    vector<Subject> subjects;
};

int main() {
    int N;
    cout << "Enter the number of students: ";
    cin >> N;
    vector<Student> students(N);

    for (int i = 0; i < N; ++i) {
        cout << "Enter ID for student " << i + 1 << ": ";
        cin >> students[i].id;
        int num_subjects;
        cout << "Enter number of subjects for student " << i + 1 << ": ";
        cin >> num_subjects;

        students[i].subjects.resize(num_subjects);

        for (int j = 0; j < num_subjects; ++j) {
            cout << "Enter subject " << j + 1 << " for student " << i + 1 << ": ";
            cin >> students[i].subjects[j].subject_name;
        }
    }

    cout << "\nStudent Information:\n";
    for (int i = 0; i < N; ++i) {
        cout << "ID: " << students[i].id << "\nSubjects:\n";
        for (int j = 0; j < students[i].subjects.size(); ++j) {
            cout << "- " << students[i].subjects[j].subject_name << endl;
        }
        cout << endl;
    }

    return 0;
}
