#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;

public:
    Vehicle(string b, int s) : brand(b), speed(s) {}

    void displayDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

class Car : public Vehicle {
protected:
    int seats;

public:
    Car(string b, int s, int seat) : Vehicle(b, s), seats(seat) {}

    void displayDetails() { 
        Vehicle::displayDetails(); 
        cout << "Seats: " << seats << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryLife;

public:
    ElectricCar(string b, int s, int seat, int battery) : Car(b, s, seat), batteryLife(battery) {}

    void displayDetails() {  
        Car::displayDetails();  
        cout << "Battery Life: " << batteryLife << " hours" << endl;
    }
};

int main() {
    ElectricCar car("Tesla", 250, 5, 10);
    cout << "\nElectric Car Details:\n";
    car.displayDetails();  

    return 0;
}
