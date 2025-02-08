#include <iostream>
using namespace std;

void DisplayAQI(int AQI[4][7], int cities, int days){
    cout<<"\n   Star representation For Every 50 Increment in AQI :\n";
    for(int i=0;i<cities;i++){
        cout<<"City "<<i+1<<":\n";
        for(int j=0;j<days;j++){
            cout<<"Day "<<j+1<<" -> "<<AQI[i][j]<<" -> ";
            int stars=AQI[i][j]/50;
            for(int k=0;k<stars;k++)cout<<"*";
            cout<<endl;
        }
        cout<<endl;
    }
}

int main() {
    int cities = 4;
    int days = 7;
    int AQI[4][7];  
    for (int i = 0; i < cities; i++) {
        cout << "     City " << i + 1 << endl;
        for (int j = 0; j < days; j++) {
            cout << "Day " << j + 1 << ": ";
            cin >> AQI[i][j];
        }
    }
    DisplayAQI(AQI,cities,days);
    return 0;
}
