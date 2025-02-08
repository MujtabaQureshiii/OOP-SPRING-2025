#include<iostream>
using namespace std;
struct Employee{
	float hoursWorked;
	string name;
	float hourlyRate;
};

Employee Details(){
	Employee employee;
	cin.ignore();
	cout<<"Enter the name of the Employee: ";
	getline(cin,employee.name);
	cout<<"Enter the how many hours employee have worked: ";
	cin>>employee.hoursWorked;
	cout<<"Enter the hourly rate: ";
	cin>>employee.hourlyRate;
	cout<<endl;
	return employee;
}

int main() {
	int num;
	cout<<"Enter the number of Employees: ";
	cin>>num;
	cout<<endl;
	Employee *employees = new Employee[num];
	for(int i=0; i<num; i++) {
		cout<<"Enter the detail of employee "<<i+1<<endl;
		employees[i] = Details();
	}
	for(int i=0;i<num;i++){
		float salary;
		salary=employees[i].hoursWorked*employees[i].hourlyRate;
		cout<<"Salary Of Employee "<<i+1<<": "<<salary<<"$";
		cout<<endl;
	}

	delete [] employees;

	return 0;
}
