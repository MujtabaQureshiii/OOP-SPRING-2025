#include <iostream>
#include <string>
using namespace std;

void ParticipantCheck(string event1[], string event2[], int N1, int N2) {
    string Name;
    cout << "\nEnter the name of Participant you want to check: ";
    getline(cin,Name);
	int found1 = 0, found2 = 0;
	for(int i=0;i<N1;i++){
        if(Name==event1[i]){
            found1=1;
            break;
        }
    }
    for (int i=0;i<N2;i++) {
        if (Name==event2[i]){
            found2=1;
            break;
        }
    }
    if(found1==1 && found2==1){
        cout<< "The Participant " << Name << " is registered in Both Events ";
    }else if(found1==1 && found2==0){
    	cout<< "The Participant " << Name << " is registered in Event No 1 ";  
    }else if(found1==0 && found2==1){
    	cout<< "The Participant " << Name << " is registered in Event No 2 ";  
    }else{
    	cout<< "The Participant " << Name << " is not registered in any Event ";
	}
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
    
    ParticipantCheck(event1, event2, N1, N2);
    return 0;
}
