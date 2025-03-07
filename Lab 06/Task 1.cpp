#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    float salary;

public:
    Employee(string n, float s) : name(n), salary(s) {}

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Manager : public Employee {
private:
    float bonus;

public:
    Manager(string n, float s, float b) : Employee(n, s), bonus(b) {}

    void displayDetails() { 
        Employee::displayDetails();
        cout << "Bonus: $" << bonus << endl;
    }
};

int main() {
    Manager mgr("Mujtaba", 50000.0, 5000.0);
    cout << "\nManager Details:\n";
    mgr.displayDetails();

    return 0;
}
