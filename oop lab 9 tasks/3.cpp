
#include <iostream>
#include <string>

using namespace std;

class Doctor;
class Billing;

class PatientRecord {
private:
    string name;
    string id;
    string dob;
    string medicalHistory;
    string billingDetails;

    void updateMedicalHistory(const string& newHistory) {
        medicalHistory = newHistory;
    }

    void addBillingDetails(const string& billingInfo) {
        billingDetails = billingInfo;
    }

    friend class Doctor;
    friend class Billing;

public:
    PatientRecord(const string& n, const string& i, const string& d)
        : name(n), id(i), dob(d) {}

    string getPublicData() const {
        return "Name: " + name + ", ID: " + id + ", DOB: " + dob;
    }
};

class Doctor {
public:
    void updateRecord(PatientRecord& record, const string& newHistory) {
        record.updateMedicalHistory(newHistory);
    }

    void viewRecord(const PatientRecord& record) {
        cout << "Doctor viewing: " << record.getPublicData() << endl;
    }
};

class Billing {
public:
    void addBilling(PatientRecord& record, const string& billingInfo) {
        record.addBillingDetails(billingInfo);
    }

    void viewRecord(const PatientRecord& record) {
        cout << "Billing viewing: " << record.getPublicData() << endl;
    }
};

class Receptionist {
public:
    void viewRecord(const PatientRecord& record) {
        cout << "Reception viewing: " << record.getPublicData() << endl;
    }
};

int main() {
    PatientRecord patient("Samana Zehra", "3628", "19-05-2005");
    Doctor dr;
    Billing bill;
    Receptionist rec;

    dr.viewRecord(patient);
    dr.updateRecord(patient, "Appendicitis");

    bill.viewRecord(patient);
    bill.addBilling(patient, "Rs. 5000 consultation");

    rec.viewRecord(patient);

    return 0;
}
