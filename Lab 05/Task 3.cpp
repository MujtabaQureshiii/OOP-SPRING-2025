#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    string designation;

public:
    Employee() : name(""), designation("") {}

    Employee(string n, string d) : name(n), designation(d) {}

    void display() const {
        cout << "Employee Name: " << name << endl;
        cout << "Designation: " << designation << endl;
    }
};

class Project {
private:
    string title;
    string deadline;
    Employee employees[5];
    int employeeCount;

public:
    Project(string t, string d) : title(t), deadline(d), employeeCount(0) {}

    void addEmployee(const Employee &e) {
        if (employeeCount < 5) {
            employees[employeeCount] = e;
            employeeCount++;
        } else {
            cout << "Project is full, cannot add more employees." << endl;
        }
    }

    void display() const {
        cout << "Project Title: " << title << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "--------------------------------" << endl;
        cout << "Assigned Employees:" << endl;
        for (int i = 0; i < employeeCount; i++) {
            employees[i].display();
            cout << "----------------------------" << endl;
        }
    }
};

int main() {
    Employee e1("Ahmed", "Software Engineer");
    Employee e2("Ali", "Project Manager");
    Employee e3("Mujtaba", "Graphic Designer");

    Project p1("Website Development", "2025-04-30");
    Project p2("Mobile App", "2025-06-15");

    p1.addEmployee(e1);
    p1.addEmployee(e2);
    p2.addEmployee(e1);
    p2.addEmployee(e3);

    cout << "Project Details:\n";
    cout << "\n\n";
    cout << "============================\n";
    p1.display();
    cout << "\n\n";
    cout << "============================\n";
    p2.display();

    return 0;
}
