#include <iostream>
using namespace std;

void CriticalPolDays(int AQI[4][28], int cities, int days) {
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

void AvgWeekly(int AQI[4][28], int cities) {
    cout << "\nWeekly Average AQI:\n";
    for (int i = 0; i < cities; i++) {
        cout << "City " << i + 1 << ": \n";
        for (int w = 0; w < 4; w++) {
            float sum = 0;
            for (int j = w * 7; j < (w + 1) * 7; j++) 
                sum += AQI[i][j];
            cout << "Week " << w + 1 << ": " << sum / 7 << " \n ";
        }
        cout << endl;
    }
}

void MinAndMaxAQI(int AQI[4][28], int cities) {
    cout << "\nHighest & Lowest AQI Values:\n";
    for (int i = 0; i < cities; i++) {
        int min = 999, max = -1;
        for (int j = 0; j < 28; j++) {
            if (AQI[i][j] > max) {
                max = AQI[i][j];
            }
            if (AQI[i][j] < min) {
                min = AQI[i][j];
            }
        }
        cout << "City " << i + 1 << ": Minimun is " << min << " And Maximun is " << max << endl;
    }
}

int main() {
    const int cities = 4, days = 28;
    int AQI[4][28];

    for (int i = 0; i < cities; i++) {
        cout << "    City " << i + 1 << ":\n";
        for (int j = 0; j < days; j++) {
            cout << "Day " << j + 1 << ": ";
            cin >> AQI[i][j];
        }
    }

    AvgWeekly(AQI, cities);
    CriticalPolDays(AQI, cities, days);
    MinAndMaxAQI(AQI, cities);

    return 0;
}
