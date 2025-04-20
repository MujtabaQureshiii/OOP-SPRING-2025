#include <iostream>
#include <string>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;
public:
    Shipment(const string& trackingNum, double w) : trackingNumber(trackingNum), weight(w) {}
    virtual ~Shipment() {}
    virtual int estimateDeliveryTime() const = 0;
    virtual void showDetails() const = 0;
};

class AirFreight : public Shipment {
    string destinationAirport;
public:
    AirFreight(const string& trackingNum, double w, const string& airport)
        : Shipment(trackingNum, w), destinationAirport(airport) {}
    
    int estimateDeliveryTime() const override {
        return (weight < 100) ? 1 : 2;
    }

    void showDetails() const override {
        cout << "Air Freight Details:\nTracking: " << trackingNumber
             << "\nWeight: " << weight << " kg\nDestination Airport: " << destinationAirport
             << "\nEstimated Delivery: " << estimateDeliveryTime() << " days" << endl;
    }
};

class GroundShipment : public Shipment {
    string destinationCity;
public:
    GroundShipment(const string& trackingNum, double w, const string& city)
        : Shipment(trackingNum, w), destinationCity(city) {}

    int estimateDeliveryTime() const override {
        return (weight < 50) ? 3 : 5;
    }

    void showDetails() const override {
        cout << "Ground Shipment Details:\nTracking: " << trackingNumber
             << "\nWeight: " << weight << " kg\nDestination City: " << destinationCity
             << "\nEstimated Delivery: " << estimateDeliveryTime() << " days" << endl;
    }
};

int main() {
    Shipment* shipment1 = new AirFreight("AIR123", 85.5, "Karachi");
    Shipment* shipment2 = new GroundShipment("GRD456", 120.0, "Islamabad");

    shipment1->showDetails();
    shipment2->showDetails();

    cout << "\nDelivery Time Estimates:\n";
    cout << "Air Freight: " << shipment1->estimateDeliveryTime() << " days\n";
    cout << "Ground Shipment: " << shipment2->estimateDeliveryTime() << " days\n";

    delete shipment1;
    delete shipment2;

    return 0;
}
