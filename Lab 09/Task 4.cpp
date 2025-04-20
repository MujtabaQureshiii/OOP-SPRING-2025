#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class WeatherSensor {
public:
    virtual ~WeatherSensor() {}
    virtual void readData() = 0;
    virtual void displayReport() const = 0;
};

class Thermometer : public WeatherSensor {
    double temperature;
public:
    Thermometer() : temperature(0.0) {}
    void readData() override {
        temperature = 15.0 + (rand() % 200) / 10.0;
    }
    void displayReport() const override {
        cout << "Thermometer Report:\nTemperature: " << temperature << "°C" << endl;
    }
};

class Barometer : public WeatherSensor {
    double pressure;
public:
    Barometer() : pressure(0.0) {}
    void readData() override {
        pressure = 950.0 + (rand() % 100);
    }
    void displayReport() const override {
        cout << "Barometer Report:\nPressure: " << pressure << " hPa" << endl;
    }
};

int main() {
    srand(time(0));
    
    WeatherSensor* sensor1 = new Thermometer();
    WeatherSensor* sensor2 = new Barometer();

    sensor1->readData();
    sensor2->readData();

    sensor1->displayReport();
    sensor2->displayReport();

    delete sensor1;
    delete sensor2;

    return 0;
}
