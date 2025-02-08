#include <iostream>
#include <string>
using namespace std;

void displayBarChart(int N1, int N2) {
    cout<<"\nBar Chart Representation:"<< endl;
    cout<<"Event 1: ";
    for(int i=0;i<N1;i++) {
        cout<<"*";
    }
    cout<<endl;
    cout<<"Event 2: ";
    for(int i=0;i<N2;i++) {
        cout<<"*";
    }
    cout<<endl;
}

int main(){
    int N1,N2;
    cout<<"Enter the No of Participants for Event 1 |Max 5|: ";
    cin>>N1;
    cout<<"Enter the No of Participants for Event 2 |Max 5|: ";
    cin>>N2;
    cin.ignore();
    string event1[N1],event2[N2];
	
    cout << "\nEnter the names of participants for Event 1:" << endl;
    for(int i=0;i<N1;i++) {
        cout << "Participant number " << i + 1 << ": ";
        getline(cin, event1[i]);
    }
    cout<< "\nEnter the names of participants for Event 2:" << endl;
    for (int i=0;i<N2;i++){
        cout << "Participant number " << i + 1 << ": ";
        getline(cin, event2[i]);
    }
    
    cout<<"\n   Event 1  \n";
    for(int i=0;i<N1;i++){
        cout<<event1[i]<<endl;
    }
    cout<<"\n   Event 2  \n";
    for(int i=0;i<N2;i++){
        cout<<event2[i]<<endl;
    }
    
    displayBarChart(N1, N2);
    
    return 0;
}
