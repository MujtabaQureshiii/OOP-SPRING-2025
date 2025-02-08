#include<iostream>
#include <cctype>
using namespace std;

string ConvertToLower(string s){
	string str = s;
		for(int i=0;i<str.length();i++){ 
			str[i] = tolower(str[i]);
		}
		return str;
}

int main() {
	int num;
	cout<<"Enter how many strings you want to sort: ";
	cin>>num;
	cout<<endl;
	string *strings = new string[num];
	for(int i=0; i<num; i++) {
		cout<<"String No "<<i+1<<" : ";
		cin>>strings[i];
	}

	cout<<endl<<"List of unsorted Strings: "<<endl;
	for(int i=0; i<num; i++) {
		cout<<strings[i]<<" ";

	}
	string temp;
	for(int i=0;i<num;i++){
		for(int j=0; j<num; j++) {
			if(ConvertToLower(strings[i]).compare(ConvertToLower(strings[j])) < 0) {
			temp = strings[i];
			strings[i] = strings[j];
			strings[j] = temp;
			}
		}

	}

cout<<endl<<"List of sorted Steings: "<<endl;
for(int i=0; i<num; i++) {
	cout<<strings[i]<<" ";

}
delete [] strings;
return 0;
}
