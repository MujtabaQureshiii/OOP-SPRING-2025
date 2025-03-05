#include <iostream>
using namespace std;

class Doctor {
private:
    string name;
    string specialization;
    int experience;

public:
    Doctor() : name(""), specialization(""), experience(0) {}

    Doctor(string n, string s, int e) : name(n), specialization(s), experience(e) {}

    void display() const {
        cout << "Doctor Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "-----------------------------" << endl;
    }
};

class Hospital {
private:
    string hospitalName;
    Doctor doctors[10];
    int doctorCount;

public:
    Hospital(string name) : hospitalName(name), doctorCount(0) {}

    void addDoctor(const Doctor &doc) {
        if (doctorCount < 10) {
            doctors[doctorCount] = doc;
            doctorCount++;
        } else {
            cout << "Hospital is full, cannot add more doctors." << endl;
        }
    }

    void display() const {
        cout << "Hospital: " << hospitalName << endl;
        cout << "----------------------------------" << endl;
        cout << "Doctors working here:" << endl;
        cout << "----------------------------------" << endl;
        for (int i = 0; i < doctorCount; i++) {
            doctors[i].display();
        }
    }
};

int main() {
    Doctor d1("Dr. Ahmed", "Cardiology", 10);
    Doctor d2("Dr. Mujtaba", "Neurology", 15);
    Doctor d3("Dr. Ali", "Orthopedics", 8);

    Hospital h1("Agha Khan Hospital");
    h1.addDoctor(d1);
    h1.addDoctor(d2);
    h1.addDoctor(d3);

    h1.display();

    return 0;
}
