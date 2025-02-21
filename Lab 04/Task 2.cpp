#include <iostream>
#include <string>
using namespace std;

class Car {
    private:
        string brand;
	    string model;
	    float rentalPrice;
	    bool available;
	
public:
	// defult constructor
	Car(){
		brand = "Unknown";
		model = "Generic";
		rentalPrice = 0.0;
		available = true;
	}
	
	//parametrized constructor
	Car(string b, string m, float p, bool avail) {
        brand = b;
        model = m;
        rentalPrice = p;
        available = avail;
    }
    
    
    void updateDetail(string newBrand, string newModel,float newPrice,bool avail){
        brand = newBrand;
        model = newModel;
        rentalPrice = newPrice;
        available = avail;
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
    }
	void displayCar() {
    cout<<"Brand: "<<brand<<endl;
    cout<<"Model: "<<model<<endl;
    cout<<"Rental Price: "<<rentalPrice<<" $ "<<endl;
    cout<<"Availability: "<<available<<endl;
    }
};
int main(){
	Car car;
    car.updateDetail("Toyota", "Corolla", 100, true);
    car.displayCar();
    cout<<"---------------"<<endl;
    car.rentalRequest(20);
    cout<<"---------------"<<endl;
    car.displayCar();
	return 0;
}
