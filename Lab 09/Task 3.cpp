#include <iostream>
#include <string>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;
public:
    Course(const string& code, int creds) : courseCode(code), credits(creds) {}
    virtual ~Course() {}
    virtual double calculateGrade() const = 0;
    virtual void displayInfo() const = 0;
};

class LectureCourse : public Course {
    double midterm;
    double finalExam;
    double assignments;
public:
    LectureCourse(const string& code, int creds, double mid, double final, double assign)
        : Course(code, creds), midterm(mid), finalExam(final), assignments(assign) {}
    double calculateGrade() const override {
        return midterm * 0.3 + finalExam * 0.5 + assignments * 0.2;
    }
    void displayInfo() const override {
        cout << "Lecture Course: " << courseCode << "\nCredits: " << credits 
             << "\nFinal Grade: " << calculateGrade() << endl;
    }
};

class LabCourse : public Course {
    double labReports;
    double finalProject;
public:
    LabCourse(const string& code, int creds, double reports, double project)
        : Course(code, creds), labReports(reports), finalProject(project) {}
    double calculateGrade() const override {
        return labReports * 0.4 + finalProject * 0.6;
    }
    void displayInfo() const override {
        cout << "Lab Course: " << courseCode << "\nCredits: " << credits 
             << "\nFinal Grade: " << calculateGrade() << endl;
    }
};

int main() {
    Course* course1 = new LectureCourse("CS101", 3, 85, 90, 80);
    Course* course2 = new LabCourse("CS102", 4, 75, 85);

    course1->displayInfo();
    course2->displayInfo();

    delete course1;
    delete course2;

    return 0;
}
