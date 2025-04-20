#include <iostream>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double pr) : dishName(name), price(pr) {}

    virtual void showDetails() const = 0;
    virtual void prepare() const = 0;

    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem {
public:
    Appetizer(string name, double pr) : MenuItem(name, pr) {}

    void showDetails() const override {
        cout << "Appetizer: " << dishName << "\nPrice: $" << price << endl;
    }

    void prepare() const override {
        cout << "Preparing appetizer: " << dishName << "\n- Chopping vegetables\n- Mixing sauce\n- Plating\n" << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double pr) : MenuItem(name, pr) {}

    void showDetails() const override {
        cout << "Main Course: " << dishName << "\nPrice: $" << price << endl;
    }

    void prepare() const override {
        cout << "Preparing main course: " << dishName << "\n- Marinating\n- Cooking\n- Garnishing\n" << endl;
    }
};

int main() {
    Appetizer dish1("Spring Rolls", 5.99);
    MainCourse dish2("Grilled Chicken", 12.50);

    MenuItem* m1 = &dish1;
    MenuItem* m2 = &dish2;

    m1->showDetails();
    m1->prepare();

    m2->showDetails();
    m2->prepare();

    return 0;
}
