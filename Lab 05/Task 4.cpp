#include <iostream>
#include <string>
using namespace std;

class AlarmSystem {
private:
    string securityLevel;

public:
    AlarmSystem(string level) : securityLevel(level) {}

    void display() const {
        cout << "Alarm System Security Level: " << securityLevel << endl;
    }
};

class SmartHome {
private:
    string home;
    AlarmSystem alarm;

public:
    SmartHome(string name, string securityLevel) : home(name), alarm(securityLevel) {}

    void display() const {
        cout << "Smart Home: " << home << endl;
        alarm.display();
    }
};

int main() {
    SmartHome home1("MQ Hotel", "Medium");
    home1.display();
    cout << "-----------------------------" << endl;
    SmartHome home2("PM House", "High");
    home2.display();

    return 0;
}
