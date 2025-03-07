#include <iostream>
using namespace std;

class Student {
private:
    const int id;
    string name;
    float *marks;
    int count;

public:
    Student() : id(-1), name("Unknown"), count(0) {
        marks = new float[20]; // Allocate space for 20 marks
    }

    Student(int id, string name) : id(id), name(name), count(0) {
        marks = new float[20]; // Allocate space for 20 marks
    }

    Student(const Student &other) : id(other.id), name(other.name), count(other.count) {
        marks = new float[20]; // Allocate new memory for marks
        for (int i = 0; i < count; i++) {
            marks[i] = other.marks[i];
        }
    }

    void addMarks(float score) {
        if (count < 20) {
            marks[count++] = score;
        } else {
            cout << "Marks array is full!" << endl;
        }
    }

    void display() {
        cout << "NAME: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "MARKS: ";
        for (int i = 0; i < count; i++) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }

    ~Student() {
        delete[] marks; 
    }
};

int main() {
    Student A(101, "Mujtaba");
    A.addMarks(85);
    A.addMarks(90);
    A.addMarks(78);

    cout << "Original Student Record:" << endl;
    A.display();

    Student B = A; 

    cout << "\nCopied Student Record:" << endl;
    B.display();

    return 0;
}
