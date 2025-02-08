#include <iostream>
#include <string>
using namespace std;

void addition(int **matrix1,int **matrix2,int **add,int rows,int column) {
    for (int i=0;i<rows;i++){
        for (int j=0;j<column;j++){
            add[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtraction(int **matrix1,int **matrix2,int **sub,int rows,int column) {
    for (int i=0;i<rows;i++){
        for (int j=0;j<column;j++){
            sub[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void display(int **matrix,int rows,int column){
    for (int i=0;i<rows;i++){
        for (int j=0;j<column;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<"\n";
    }
}
int main() {
    
    int rows,column;
    cout<<"Enter the no of rows of matrices: ";
    cin>>rows;
    cout<<"Enter the no of Columns of matrices: ";
    cin>>column;
    
    int **matrix1 = new int*[rows];
    
    int **matrix2 = new int*[rows];
    
    for (int i = 0; i < rows; i++) {
        matrix1[i] = new int[column];
        matrix2[i] = new int[column];
    }
	cout<<"------------------------------------"<<endl;
    cout<<"    MATRIX 1 \n";
    for (int i=0;i<rows;i++) {
        for (int j=0;j<column;j++) {
            cout<<"Enter Element ["<<i<<" "<<j<<"]: ";
            cin>>matrix1[i][j];
            
        }
    }
    cout<<"------------------------------------"<<endl;
    cout<<"    MATRIX 2 \n";
    for (int i=0;i<rows;i++) {
        for (int j=0;j<column;j++) {
            cout<<"Enter Element ["<<i<<" "<<j<<"]: ";
            cin>>matrix2[i][j];
        }
    }
    
    int **add = new int*[rows];
    int **sub = new int*[rows];
    for (int i=0;i<rows;i++){
        add[i] = new int[column];
        sub[i] = new int[column];
    }

    addition(matrix1,matrix2,add,rows,column);
    subtraction(matrix1,matrix2,sub,rows,column);
	cout<<"------------------------------------"<<endl;
    cout<<"The Result of Addition is "<<endl;
    display(add,rows,column);
    cout<<"------------------------------------"<<endl;
    cout<<"\nThe Result of Subraction is "<<endl;
    display(sub,rows,column);
	cout<<"------------------------------------"<<endl;
    for (int i = 0; i < rows; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] add[i];
        delete[] sub[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] add;
    delete[] sub;

    return 0;
}
