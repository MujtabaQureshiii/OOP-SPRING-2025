#include <iostream>
using namespace std;

void CriticalPolDays(int AQI[4][7], int cities, int days) {
    cout << "\n    Critical Pollution Days \n";
    for (int i = 0; i < cities; i++) {
        bool dayCritical = false;
        cout << "City " << i + 1 << ": ";
        for (int j = 0; j < days; j++) {
            if (AQI[i][j] > 150) {
                cout << "Day " << j + 1 << " (AQI: " << AQI[i][j] << ") ";
                dayCritical = true;
            }
        }
        if (!dayCritical) {
            cout << "No critical pollution days.";
        }
        cout << endl;
    }
}

int main() {
    int cities = 4;
    int days = 7;
    int AQI[4][7];  
    for (int i = 0; i < cities; i++) {
        cout << "    City " << i + 1 << endl;
        for (int j = 0; j < days; j++) {
            cout << "Day " << j + 1 << ": ";
            cin >> AQI[i][j];
        }
    }
    CriticalPolDays(AQI, cities, days);
    return 0;
}
