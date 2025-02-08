#include <iostream>
using namespace std;

void Average(float avg[],int cities){
    int index=0;
    float worstAverage = avg[0];
    for(int i=0;i<cities;i++){
        if (avg[i]>worstAverage){
            worstAverage = avg[i];
            index = i;
        }
    }
    cout << "\nAverage AQI over the week:\n";
    for (int i=0;i<cities;i++) {
        cout<<"City "<<i + 1<<": "<<avg[i]<<endl;
    }

    cout << "\nThe city with the worst air quality is City " << index + 1 
    << " with an average AQI of " << worstAverage << "\n";
}
int main() {
    int cities = 4;
    int days = 7;
    int AQI[cities][days];
    float avg[cities];
    
    // taking inputs for each city
    for (int i=0;i<cities;i++){
        cout<<"    City "<<i+1<<endl;
        for(int j=0;j<days;j++){
            cout<<"Day "<<j+1<< ": ";
            cin>>AQI[i][j];
        }
    }

    for (int i=0;i<cities;i++){
        int sum = 0;
        for (int j=0;j<days;j++){
            sum=sum+AQI[i][j];
        }
        avg[i] = sum/days;
    }
    Average(avg,cities);
    return 0;
}
