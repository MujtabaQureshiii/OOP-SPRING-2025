#include <iostream>
using namespace std;

int main() {
    int pages,rows,columns;
    cout<<"      Enter the dimensions of the 3D array "<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Enter the No of Pages: ";
    cin>>pages;
    cout<<"Enter the Rows: ";
    cin>>rows;
    cout<<"Enter the Columns: ";
    cin>>columns;
    

    int*** array = new int**[pages];
    for (int i=0;i<pages;i++) {
        array[i] = new int*[rows];
        for (int j=0;j<rows;j++) {
            array[i][j] = new int[columns];
        }
    }
	cout<<"-------------------------------------"<<endl;
    cout<<"   ELEMENTS OF 3D ARRAY"<<endl;
    for (int i=0;i<pages;i++) {
        for (int j=0;j<rows;j++) {
            for (int k=0;k<columns;k++) {
                cout<<"ENTER ELEMENT ["<<i<<", "<<j<<", "<<k<<"]: ";
                cin>>array[i][j][k];
                cin.ignore(); 
            }
        }
    }
	cout<<"-------------------------------------"<<endl;
    cout<<"   3D array"<<endl;
    for (int i=0;i<pages;i++) {
        cout<<"_____________"<<endl;
        for (int j=0;j<rows;j++) {
            for (int k=0;k<columns;k++) {
                cout<<array[i][j][k]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    for (int i=0;i<pages;i++) {
        for (int j=0;j<rows;j++) {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
