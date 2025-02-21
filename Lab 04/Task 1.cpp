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
	Car(){
		brand = "Unknown";
		model = "Generic";
		rentalPrice = 0.0;
		available = true;
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
	void rentalRequest(){
		if(available==true){
			cout<<"Car is rented successfully "<<endl;
		}
		else{
			cout<<"car is not available for rent";
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
    car.updateDetail("Toyota","Corolla",100,true);
	car.displayCar();
    cout<<"_________________"<<endl;
	car.rentalRequest();
	return 0;
}
