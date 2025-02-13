#include<iostream>
#include<string>
using namespace std;

class Wallet{
	private:
		string ownerName;
		float totalBalance;
		string transactionHistory[50];
		int transactionNo;
	public:
		
		Wallet(string Name) {
            ownerName=Name;
            totalBalance=0.0;
            transactionNo=0;
        }
		
		void addMoney(float MoneyAmount){
			totalBalance=totalBalance+MoneyAmount;
			cout<<"Money added successfully!"<<endl;
			if(transactionNo<50){
				transactionHistory[transactionNo]=to_string(MoneyAmount)+"$ desposited in your Account";
				transactionNo=transactionNo+1;				
			}
			else{
				cout<<"Transaction History is Full!!";				
			}
		}
		
		void spendMoney(float MoneyAmount){
			if(MoneyAmount>0 && MoneyAmount<=totalBalance){
                totalBalance=totalBalance-MoneyAmount;
                cout<<"Transaction successful!\n";
                if (transactionNo<50){
                    transactionHistory[transactionNo] = to_string(MoneyAmount)+"$ is spent from your Account";
                    transactionNo=transactionNo+1;
                }
                else{
                	cout<<"Transaction History is Full!!";
				}
		}
			else{
				cout<<"Insufficient balance or invalid amount!\n";
				
			}	
                
            
				
		}
		
		void displayHistory(){
			cout<<"--------------------------------"<<endl;
			cout<<"   Displaying Transaction History"<<endl;
			cout<<"--------------------------------"<<endl;
			for(int i=0;i<transactionNo;i++) {
                cout<<transactionHistory[i]<<endl;
            }
            cout<<"--------------------------------"<<endl;
		}	
	
		
};


int main(){
	string Name;
    cout<<"ENTER THE ACCOUNT NAME: ";
    getline(cin,Name);
    cout<<"--------------------------------"<<endl;
    cout<<"    TRANSACTION OF "<<Name<<endl;
    cout<<"--------------------------------"<<endl;
    Wallet wallet(Name);
    wallet.addMoney(1000);
    wallet.spendMoney(500);
    wallet.displayHistory();
    wallet.addMoney(1500);
    wallet.spendMoney(60);
    wallet.displayHistory();
    return 0;
	
}
