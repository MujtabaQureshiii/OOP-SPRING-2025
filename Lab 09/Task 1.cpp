#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}

    virtual void displayTreatment() const = 0;
    virtual double calculateCost() const = 0;

    virtual ~Patient() {}
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "InPatient Treatment for " << name << " (ID: " << id << "):\n";
        cout << "- Room admitted\n- IV Medications\n- Regular monitoring\n";
    }

    double calculateCost() const override {
        return 1500.0;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "OutPatient Treatment for " << name << " (ID: " << id << "):\n";
        cout << "- Routine checkup\n- Prescription medicine\n- Lab tests\n";
    }

    double calculateCost() const override {
        return 300.0;
    }
};

int main() {
    InPatient p1("Mujtaba", "IP001");
    OutPatient p2("Ali", "OP001");

    Patient* patient1 = &p1;
    Patient* patient2 = &p2;

    patient1->displayTreatment();
    cout << "Cost: $" << patient1->calculateCost() << "\n\n";

    patient2->displayTreatment();
    cout << "Cost: $" << patient2->calculateCost() << "\n";

    return 0;
}
