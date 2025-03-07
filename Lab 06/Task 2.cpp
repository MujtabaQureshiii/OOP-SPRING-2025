#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;

public:
    Vehicle(string b, int s) {
        brand = b;
        speed = s;
    }

    void displayVehicleDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(string b, int s, int seat) : Vehicle(b, s) {
        seats = seat;
    }

    void displayCarDetails() {
        displayVehicleDetails();
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;

public:
    ElectricCar(string b, int s, int seat, int battery) : Car(b, s, seat) {
        batteryLife = battery;
    }

    void displayElectricCarDetails() {
        displayCarDetails();
        cout << "Battery Life: " << batteryLife << " hours" << endl;
    }
};

int main() {
    ElectricCar Car("Tesla", 250, 5, 10);
    cout << "\nElectric Car Details:\n";
    Car.displayElectricCarDetails();

    return 0;
}
