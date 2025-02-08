#include <iostream>
#include <string>
using namespace std;

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
    
    int total=N1+N2;
    int Dontation=total*10;
    cout<<"\nTOTAL DONATION : "<<Dontation<<"$";

    
    return 0;
}

