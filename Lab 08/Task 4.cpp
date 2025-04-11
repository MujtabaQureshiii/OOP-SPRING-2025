#include <iostream>
#include <string>
using namespace std;

class Car;

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice);
    void displayCar(const Car& car);
};

class Car {
private:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}
    friend class InventoryManager;
    friend void comparePrice(const Car& c1, const Car& c2);
};

void InventoryManager::updatePrice(Car& car, double newPrice) {
    car.price = newPrice;
}

void InventoryManager::displayCar(const Car& car) {
    cout << "Model: " << car.model << ", Price: $" << car.price << endl;
}

void comparePrice(const Car& c1, const Car& c2) {
    if (c1.price > c2.price)
        cout << c1.model << " is more expensive." << endl;
    else if (c2.price > c1.price)
        cout << c2.model << " is more expensive." << endl;
    else
        cout << "Both cars are priced equally." << endl;
}

int main() {
    Car car1("Toyota Corolla", 25000);
    Car car2("Honda Civic", 27000);

    InventoryManager manager;
    manager.displayCar(car1);
    manager.displayCar(car2);

    comparePrice(car1, car2);

    manager.updatePrice(car1, 28000);
    cout << "\nAfter price update:\n";
    manager.displayCar(car1);

    comparePrice(car1, car2);

    return 0;
}
