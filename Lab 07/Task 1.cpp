#include <iostream>
#include <string>
using namespace std;


class Device {
protected:
    int deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(int id, string name, string loc = "") : deviceID(id), deviceName(name), status(false), location(loc) {}

    virtual void turnOn() {
        status = true;
        cout << deviceName << " turned ON.\n";
    }

    virtual void turnOff() {
        status = false;
        cout << deviceName << " turned OFF.\n";
    }

    virtual void getStatus() {
        cout << deviceName << " is " << (status ? "ON" : "OFF") << ".\n";
    }

    virtual void displayInfo() {
        cout << "Device ID: " << deviceID << "\nName: " << deviceName << "\nStatus: " << (status ? "ON" : "OFF") << "\nLocation: " << location << endl;
    }

    virtual ~Device() {}
};


class Light : public Device {
private:
    int brightnessLevel;
    string colorMode;

public:
    Light(int id, string name, string loc, int brightness, string color)
        : Device(id, name, loc), brightnessLevel(brightness), colorMode(color) {}

    void displayInfo() override {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << "\nColor Mode: " << colorMode << endl;
    }
};


class Thermostat : public Device {
private:
    double temperature;
    string mode; 
    double targetTemperature;

public:
    Thermostat(int id, string name, string loc, double temp, string mod, double targetTemp)
        : Device(id, name, loc), temperature(temp), mode(mod), targetTemperature(targetTemp) {}

    void getStatus() override {
        cout << deviceName << " Mode: " << mode << ", Current Temp: " << temperature << "°C, Target Temp: " << targetTemperature << "°C\n";
    }
};


class SecurityCamera : public Device {
private:
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string name, string loc, string res, bool nightVision)
        : Device(id, name, loc), resolution(res), recordingStatus(false), nightVisionEnabled(nightVision) {}

    void turnOn() override {
        Device::turnOn();
        recordingStatus = true;
        cout << deviceName << " started recording.\n";
    }
};


class SmartPlug : public Device {
private:
    double powerConsumption;
    int timerSetting;

public:
    SmartPlug(int id, string name, string loc, double power, int timer)
        : Device(id, name, loc), powerConsumption(power), timerSetting(timer) {}

    void turnOff() override {
        Device::turnOff();
        cout << deviceName << " logged power usage: " << powerConsumption << " kWh.\n";
    }
};

int main() {
    Light light(1, "Living Room Light", "Living Room", 80, "Warm White");
    Thermostat thermostat(2, "Smart Thermostat", "Bedroom", 22.5, "Cooling", 24);
    SecurityCamera camera(3, "Front Door Camera", "Entrance", "1080p", true);
    SmartPlug plug(4, "Smart Plug", "Kitchen", 1.5, 60);

    cout << "=== Device Information ===\n";
    light.displayInfo();
    thermostat.getStatus();
    camera.turnOn();
    plug.turnOff();

    return 0;
}
