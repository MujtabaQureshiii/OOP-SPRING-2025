#include <iostream>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    float marks[3];
};
int main() {
    int num;
    cout<<"Enter how many student: ";
    cin>>num;
    Student* students = new Student[num];
    for (int i=0;i<num;i++) {
        cout<<"\nDetail Of Student No "<<i + 1<<":\n";
        cout<<"Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout<<"Roll #: ";
        cin>>students[i].rollNumber;
        cout<<"Enter the marks for any 3 subjects: \n";
        for (int j = 0; j < 3; j++) {
            cout<<"Mark No "<<j+1<<": ";
            cin>>students[i].marks[j];
            }
    }
    cout<<"\nSTUDENT RECORD:\n";
    for (int i=0;i<num;i++) {
        float sum = 0;
        for (int j = 0; j < 3; j++) {
			sum += students[i].marks[j];	
		}
        cout<<"\nStudent No "<<i + 1<<":\n";
        cout<<"Name: "<<students[i].name<<"\n";
        cout<<"Roll #: "<<students[i].rollNumber<<"\n";
        cout<<"AVERAGE marks: "<<sum / 3<<"\n";
    }
    delete[] students;
    return 0;
}

