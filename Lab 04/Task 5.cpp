#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string brand;
	    string model;
	    float rentalPrice;
	    bool available;
	    float totalRevenue = 0.0;
	    string carID;
	
public:
	// Default constructor
    Car() : brand("Unknown"), model("Generic"), rentalPrice(0.0), available(true), totalRevenue(0.0), carID("N/A") {}

    // Parameterized constructor 
    Car(string id, string b, string m, float p, bool avail) : carID(id), brand(b), model(m), rentalPrice(p), available(avail), totalRevenue(0.0) {}

    // Copy constructor
    Car(const Car &car) : carID(car.carID), brand(car.brand), model(car.model), rentalPrice(car.rentalPrice), available(car.available), totalRevenue(car.totalRevenue) {}

    // Destructor
    ~Car() {
        cout << "Car object with model " << model << " is being removed from memory.\n";
    }

    
    
    void updateDetail(string id,string newBrand, string newModel,float newPrice,bool avail){
        brand = newBrand;
        model = newModel;
        rentalPrice = newPrice;
        available = avail;
        carID = id;
    }
    bool availability(){
        return available;
    }
	void rentalRequest(int days) {
        if (available==false) {
            cout<<"Car is not available for rent."<<endl;
            return;
        }
        if (days > 5 && days<10) {
            available = false;
            rentalPrice = rentalPrice - (0.05 * rentalPrice);
            cout<<"Car is successfully rented !!!"<<endl<< "You got a 5% discount for renting the car for more than 5 days."<<endl;
            cout<<"Rental Price: "<<rentalPrice<<" $ "<<endl;
        }else if (days > 10) {
            available = false;
            rentalPrice = rentalPrice - (0.01 * rentalPrice);
            cout<<"Car is successfully rented !!!"<<endl<< "You got a 10% discount for renting the car for more than 5 days."<<endl;
            cout<<"Rental Price: "<<rentalPrice<<" $ "<<endl;
        }
        else {
            available = false;
            cout<<"\nCar is successfully rented.";
            cout<<"Rental Price: "<<rentalPrice<<" $ "<<endl;
        }
        
        this->totalRevenue += (this->rentalPrice*days);
    }
	void displayCar() {
	cout<<"Car ID: "<<carID<<endl;
    cout<<"Brand: "<<brand<<endl;
    cout<<"Model: "<<model<<endl;
    cout<<"Rental Price: "<<rentalPrice<<" $ "<<endl;
    cout<<"Availability: "<<available<<endl;
    cout<<"Total Revenue: "<<totalRevenue<<" $ "<<endl;
    }
};
int main(){
	Car car("BG999","Toyota", "Corolla", 100, true);
	cout<<"-------------------"<<endl;
    car.displayCar();
    cout<<"-------------------"<<endl;
    car.rentalRequest(9);
    cout<<"-------------------"<<endl;
    car.displayCar();
    cout<<"-------------------"<<endl;
    car.updateDetail("AB247","Toyota", "Altas", 120, true);
    car.rentalRequest(15);
    cout<<"-------------------"<<endl;
    car.displayCar();
    cout<<"-------------------"<<endl;
	return 0;
}
