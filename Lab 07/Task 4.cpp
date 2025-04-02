#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string name, int age, string contactNumber, string address = "")
        : name(name), age(age), contactNumber(contactNumber), address(address) {}

    virtual void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age
             << "\nContact: " << contactNumber
             << "\nAddress: " << address << endl;
    }

    virtual void updateInfo(string newContact, string newAddress) {
        contactNumber = newContact;
        if (!newAddress.empty()) {
            address = newAddress;
        }
    }

    virtual ~Person() {}
};

class Patient : public Person {
private:
    int patientID;
    string medicalHistory;
    string doctorAssigned;

public:
    Patient(string name, int age, string contactNumber, int patientID, string medicalHistory, string doctorAssigned, string address = "")
        : Person(name, age, contactNumber, address), patientID(patientID), medicalHistory(medicalHistory), doctorAssigned(doctorAssigned) {}

    void displayInfo() override {
        cout << "\n--- Patient Info ---" << endl;
        Person::displayInfo();
        cout << "Patient ID: " << patientID
             << "\nMedical History: " << medicalHistory
             << "\nDoctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
private:
    string specialization;
    double consultationFee;
    int patientsList[10]; 
    int patientCount;

public:
    Doctor(string name, int age, string contactNumber, string specialization, double fee, string address = "")
        : Person(name, age, contactNumber, address), specialization(specialization), consultationFee(fee), patientCount(0) {}

    void addPatient(int patientID) {
        if (patientCount < 10) {
            patientsList[patientCount++] = patientID;
        } else {
            cout << "Patient list is full!" << endl;
        }
    }

    void displayInfo() override {
        cout << "\n--- Doctor Info ---" << endl;
        Person::displayInfo();
        cout << "Specialization: " << specialization
             << "\nConsultation Fee: $" << consultationFee
             << "\nPatients Assigned: ";
        for (int i = 0; i < patientCount; i++)
            cout << patientsList[i] << " ";
        cout << endl;
    }
};

class Nurse : public Person {
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string name, int age, string contactNumber, string assignedWard, string shiftTimings, string address = "")
        : Person(name, age, contactNumber, address), assignedWard(assignedWard), shiftTimings(shiftTimings) {}

    void displayInfo() override {
        cout << "\n--- Nurse Info ---" << endl;
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard
             << "\nShift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
private:
    string department;
    double salary;

public:
    Administrator(string name, int age, string contactNumber, string department, double salary, string address = "")
        : Person(name, age, contactNumber, address), department(department), salary(salary) {}

    void updateInfo(string newDepartment, double newSalary) {
        department = newDepartment;
        salary = newSalary;
    }

    void displayInfo() override {
        cout << "\n--- Administrator Info ---" << endl;
        Person::displayInfo();
        cout << "Department: " << department
             << "\nSalary: $" << salary << endl;
    }
};

int main() {
    Patient p1("Mujtaba", 30, "123-456-7890", 101, "Diabetes", "Dr. Ayesha");
    Doctor d1("Ali", 45, "987-654-3210", "Cardiology", 200.0);
    Nurse n1("Ahmed", 28, "111-222-3333", "ICU", "Night");
    Administrator a1("Mr. Basheer", 50, "999-888-7777", "HR", 5000.0);

    d1.addPatient(101);

    p1.displayInfo();
    d1.displayInfo();
    n1.displayInfo();
    a1.displayInfo();

    return 0;
}
