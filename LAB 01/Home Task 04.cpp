#include <iostream>
using namespace std;

void Avg(int AQI[4][28], int cities, int days, float avg[4]) {
    cout << "\n   Average AQI(Monthly):\n";
    for (int i = 0; i < cities; i++) {
        int sum = 0;
        for (int j = 0; j < days; j++) {
            sum += AQI[i][j];
        }
        avg[i] = sum / (float)days;
        cout << "City " << i + 1 << ": " << avg[i] << endl;
    }
}

void LargestDrop(int AQI[4][28], int cities) {
    float max = 0;
    int best = -1;
    for (int i = 0; i < cities; i++) {
        float firstWeek = 0, lastWeek = 0;
        for (int j = 0; j < 7; j++) {
            firstWeek += AQI[i][j];
        }
        for (int j = 21; j < 28; j++) {
            lastWeek += AQI[i][j];
        }
        firstWeek /= 7.0;
        lastWeek /= 7.0;
        float drop = firstWeek - lastWeek;
        if (drop > max) {
            max = drop;
            best = i + 1;
        }
    }
    if (best != -1) {
        cout << "\nCity " << best << " has improved most with a drop of " << max << ".\n";
    } else {
        cout << "\nNo major improvement in air quality.\n";
    }
}

int main() {
    const int cities = 4, days = 28;
    int AQI[cities][days];
    float avg[cities];

    for (int i = 0; i < cities; i++) {
        cout << "    City " << i + 1 << ":\n";
        for (int j = 0; j < days; j++) {
            cout << "Day " << j + 1 << ": ";
            cin >> AQI[i][j];
        }
    }

    Avg(AQI, cities, days, avg);
    LargestDrop(AQI, cities);
    return 0;
}

