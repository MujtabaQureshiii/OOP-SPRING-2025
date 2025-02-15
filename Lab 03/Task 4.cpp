#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    double fuelCapacity;
    double currentFuelLevel;

public:
	// constructor to set values in variable
    Car(string Brand, string Model, float Capacity) {
        brand = Brand;
        model = Model;
        fuelCapacity = Capacity;
        currentFuelLevel = Capacity;
    }

    void Drive(double fuelUsed) {
        if (fuelUsed > 0 && fuelUsed <= currentFuelLevel) {
            currentFuelLevel -= fuelUsed;
            cout<<"You have used "<<fuelUsed<<" liters of fuel And "<<currentFuelLevel<<" is Left!"<<endl;
            if (currentFuelLevel < 3){
                cout<<"Your Fuel level is low!!!!"<<endl;
            }
        } else { 
            cout<<"Invalid Fuel Used!"<<endl;
            }
    }

    void refuel(double FuelAmount) {
        if (FuelAmount > 0 && (currentFuelLevel + FuelAmount) <= fuelCapacity) {
            currentFuelLevel += FuelAmount;
            cout<<"Refueled "<<FuelAmount<<" liters.\nCurrent fuel: "<<currentFuelLevel<<" liters."<<endl;
        } else{
            cout<<"Tank capacity exceeded Or Invalid Fuel Amount.\n";
            }
    }

    void checkFuelStatus() {
        cout<<"Current fuel level: "<<currentFuelLevel<<" liters."<<endl;
    }
};

int main() {
    Car car("Honda", "Civic", 35);
    car.checkFuelStatus();
    car.Drive(10);
    car.Drive(12);
    car.checkFuelStatus();
    car.Drive(20);
    car.refuel(15);
    car.checkFuelStatus();
    return 0;
}
