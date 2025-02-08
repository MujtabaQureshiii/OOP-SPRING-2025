#include<iostream>
using namespace std;
struct Book{
	int year;
	string author;
	string title;
};

Book BookDetails(){
	cout<<endl;
	Book book;
	cin.ignore();
	cout<<"Enter the Title of the Book: ";
	getline(cin,book.title);
	cout<<"Enter the author of the Book: ";
	getline(cin,book.author);
	cout<<"Enter the Year the Book is Published: ";
	cin>>book.year;
	cout<<endl;
	return book;
}
void display(Book book){
	cout<<endl<<"Title: "<<book.title<<endl;
	cout<<"Author: "<<book.author<<endl;
	cout<<"Year Of Publish: "<<book.year<<endl;
}

int main() {
	int num;
	cout<<"Enter the number of Books: ";
	cin>>num;
	cout<<endl;
	Book *books=new Book[num];
	for(int i=0; i<num; i++) {
		cout<<"Enter the detail of Book No "<<i+1<<endl;
		books[i] = BookDetails();
	}
	int Year;
	cout<<"Enter the specific year: ";
	cin>>Year;
	
	for(int i=0; i<num; i++) {
		if(books[i].year>=Year){
			display(books[i]);
		}
	}

	delete [] books;

	return 0;
}
