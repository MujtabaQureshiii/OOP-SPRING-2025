#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPersonDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : public Person {
protected:
    string subject;

public:
    Teacher(string n, int a, string sub) : Person(n, a) {
        subject = sub;
    }

    void displayTeacherDetails() {
        displayPersonDetails();
        cout << "Subject: " << subject << endl;
    }
};

class Researcher : public Teacher {
protected:
    string researchArea;

public:
    Researcher(string n, int a, string sub, string res) : Teacher(n, a, sub) {
        researchArea = res;
    }

    void displayResearcherDetails() {
        displayTeacherDetails();
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Researcher {
private:
    int publications;

public:
    Professor(string n, int a, string sub, string res, int pub) : Researcher(n, a, sub, res) {
        publications = pub;
    }

    void displayProfessorDetails() {
        displayResearcherDetails();
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    Professor prof("Mr.Mujtaba", 45, "Computer Science", "Artificial Intelligence", 25);
    cout << "\nProfessor Details:\n";
    prof.displayProfessorDetails();

    return 0;
}
