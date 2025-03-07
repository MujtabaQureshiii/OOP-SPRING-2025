#include <iostream>
using namespace std;

class Apartment {
    const int id;
    string address;
    string *name;

public:
    Apartment() : id(-1), name(nullptr), address("") {}

    Apartment(int id, string address, string ownerName) : id(id), address(address) {
        name = new string(ownerName);
    }

    void display() {
        cout << "NAME: " << *name << endl;
        cout << "ID: " << id << endl;
        cout << "ADDRESS: " << address << endl;
    }

    Apartment(const Apartment &other) : id(other.id), address(other.address), name(other.name) {}

    ~Apartment() {
        delete name;
    }
};

int main() {
    Apartment A(120, "Karachi", "Mujtaba");
    Apartment B(A); 

    cout << "Original Apartment:\n";
    A.display();
    
    cout << "\nCopied Apartment:\n";
    B.display();

    return 0;
}
