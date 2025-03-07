#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;

public:
    Device(int id, bool st) : deviceID(id), status(st) {}

    void displayDetails() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Status: " << status << endl;
    }
};

class SmartPhone : public Device {
protected:
    float screenSize;

public:
    SmartPhone(int id, bool st, float size) : Device(id, st), screenSize(size) {}

    void displayDetails() {
        Device::displayDetails();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};

class SmartWatch : public SmartPhone {
protected:
    bool heartRateMonitor;

public:
    SmartWatch(int id, bool st, float size, bool hrm) : SmartPhone(id, st, size), heartRateMonitor(hrm) {}

    void displayDetails() {
        SmartPhone::displayDetails();
        cout << "Heart Rate Monitor: " << heartRateMonitor << endl;
    }
};

class SmartWearable : public SmartWatch {
private:
    int stepCounter;

public:
    SmartWearable(int id, bool st, float size, bool hrm, int steps) 
        : SmartWatch(id, st, size, hrm), stepCounter(steps) {}

    void displayDetails() {
        SmartWatch::displayDetails();
        cout << "Step Counter: " << stepCounter << endl;
    }
};

int main() {
    SmartWearable device(101, true, 6.5, true, 1200);
    cout << "\nSmart Wearable Device Details:\n";
    device.displayDetails();

    return 0;
}
