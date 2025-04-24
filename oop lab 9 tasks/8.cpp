#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    virtual double getTuition(string status, int creditHours) = 0;
    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    double getTuition(string status, int creditHours) override {
        double rate = 0;

        if (status == "undergraduate") {
            rate = 200;
        } else if (status == "graduate") {
            rate = 300;
        } else if (status == "doctoral") {
            rate = 400;
        } else {
            cout << "Invalid status. Setting rate to 0.\n";
        }

        return rate * creditHours;
    }
};

int main() {
    GraduateStudent grad;

    string topic;
    cout << "Enter research topic: ";
    getline(cin, topic);
    grad.setResearchTopic(topic);

    string status;
    int creditHours;

    cout << "Enter student status (undergraduate / graduate / doctoral): ";
    cin >> status;

    cout << "Enter number of credit hours: ";
    cin >> creditHours;

    double tuition = grad.getTuition(status, creditHours);

    cout << "\nStudent Type: " << status << endl;
    cout << "Research Topic: " << grad.getResearchTopic() << endl;
    cout << "Credit Hours: " << creditHours << endl;
    cout << "Total Tuition: $" << tuition << endl;

    return 0;
}
