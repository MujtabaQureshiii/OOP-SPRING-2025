#include <iostream>
#include <string>
using namespace std;

class Library {
    private:
        string bookList[50];
        string borrowedBooks[50];
        string availableBooks[50];
        int TotalBooks;
        int Borrowed;
        int Available;

    public:
        // Default constructor
        Library() {
            TotalBooks = 0;
            Borrowed = 0;
            Available = 0;
        }
    
        void addBook(string bookName) {
            if (TotalBooks < 50) {
                bookList[TotalBooks] = bookName;
                availableBooks[Available] = bookName;
                TotalBooks++;
                Available++;
                cout<<"Book added in the library."<<endl;
            } else {
                cout << "Library is full!!!"<<endl;
            }
        }

        void lendBook(string bookName) {
            for (int i = 0; i < Available; i++) {
                if (availableBooks[i] == bookName) {
                    borrowedBooks[Borrowed] = bookName;
                    Borrowed++;

                    for (int j = i; j < Available - 1; j++) {
                        availableBooks[j] = availableBooks[j + 1];
                    }
                    Available--;

                    cout <<"Book has been borrowed"<<endl;
                    return;
                }
            }
            cout <<"This book is not available."<<endl;
        }
    
        void returnBook(string bookName) {
            for (int i = 0; i < Borrowed; i++) {
                if (borrowedBooks[i] == bookName) {
                    availableBooks[Available] = bookName;
                    Available++;
                    for (int j = i; j < Borrowed - 1; j++) {
                        borrowedBooks[j] = borrowedBooks[j + 1];
                    }
                    Borrowed--;
                    cout <<"Book has been returned successfully."<<endl;
                    return;
                }
            }
            cout << bookName << " was not borrowed.\n";
        }
    	void DisplayBorrowedBooks() {
    		cout <<"\n";
    		cout <<"\n";
            cout <<"-------------------------"<<endl;
			cout <<"Borrowed Books:\n";
			cout <<"-------------------------"<<endl;
            for (int i = 0; i < Borrowed; i++) {
                cout << i+1<< "."<< borrowedBooks[i] <<endl;
            }
            cout <<"-------------------------"<<endl;
            cout <<"\n";
            cout <<"\n";
        }
        void DisplayAvailableBooks() {
        	cout <<"\n";
        	cout <<"\n";
        	cout <<"-------------------------"<<endl;
            cout << "Available Books:\n";
            cout <<"-------------------------"<<endl;
            for (int i = 0; i < Available; i++) {
                cout << i+1<< "."<< availableBooks[i] <<endl;
            }
            cout <<"-------------------------"<<endl;
            cout <<"\n";
            cout <<"\n";
        }
        void DisplayTotalBooks() {
        	cout <<"\n";
        	cout <<"\n";
        	cout <<"-------------------------"<<endl;
            cout << "All Books In The Library:\n";
            cout <<"-------------------------"<<endl;
            for (int i = 0; i < TotalBooks; i++) {
                cout << i+1<< "."<< bookList[i] <<endl;
            }
            cout <<"-------------------------"<<endl;
            cout <<"\n";
            cout <<"\n";
        }
    
        
};

int main() {
    Library library;
    library.addBook("The Lion King");
    library.addBook("Madness");
    library.addBook("Hustle Is Real");
    library.addBook("Bang");
    library.DisplayAvailableBooks();
    library.lendBook("Bang");
    library.DisplayAvailableBooks();
    library.DisplayBorrowedBooks();
    library.returnBook("Bang");
    library.lendBook("The Lion King");
    library.DisplayAvailableBooks();
    library.DisplayBorrowedBooks();
    library.DisplayTotalBooks();

    return 0;
}
