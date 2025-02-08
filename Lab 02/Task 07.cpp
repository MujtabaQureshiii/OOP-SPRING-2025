#include <iostream>
using namespace std;

void multiplication(int** matrix1, int** matrix2, int** result, int row1, int col1, int row2, int col2) {
    for(int i=0;i<row1;i++) {
        for(int j=0;j<col2;j++) {
            result[i][j]=0;
            
            for(int k=0;k<col1;k++) {
                result[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }
}

int main() {
    int row1,col1,row2,col2;
    cout<<"Enter rows and columns for Matrix No 1 "<<endl;
    cout<<"Enter Rows: ";
    cin>>row1;
    cout<<"Enter Columns: ";
    cin>>col1;
	 
    cout<<"Enter rows and columns for Matrix No 2 \n";
    cout<<"Enter Rows: ";
    cin>>row2;
    cout<<"Enter Columns: ";
    cin>>col2;
	cout<<"---------------------------------"<<endl;
    if(col1!=row2) {
        cout<<"MATRIX MULTIPLICATION IS NOT POSSIBLE"<<endl;
        return 1;
    }
	cout<<"---------------------------------"<<endl;
    int** matrix1=new int*[row1];
    for(int i=0;i<row1;i++) {
        matrix1[i]=new int[col1];
    }

    int** matrix2=new int*[row2];
    for(int i=0;i<row2;i++) {
        matrix2[i]=new int[col2];
    }

    int** result=new int*[row1];
    for(int i=0;i<row1;++i) {
        result[i]=new int[col2];
    }
    cout<<"---------------------------------"<<endl;
    cout<<"   MATRIX NO 1\n"<<endl;
    for(int i=0;i<row1;++i) {
        for(int j=0;j<col1;++j) {
        	cout<<"Enter Element ["<<i<<" "<<j<<"]: ";
            cin>>matrix1[i][j];
        }
    }
    cout<<"---------------------------------"<<endl;
    cout<<"   MATRIX NO 2\n"<<endl;
    for(int i=0;i<row2;++i) {
        for(int j=0;j<col2;++j) {
        	cout<<"Enter Element ["<<i<<" "<<j<<"]: ";
            cin>>matrix2[i][j];
        }
    }
    multiplication(matrix1,matrix2,result,row1,col1,row2,col2);
    cout<<"---------------------------------"<<endl;
    cout<<"   RESULT"<<endl;
    for(int i=0;i<row1;++i) {
        for(int j=0;j<col2;++j) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
	cout<<"---------------------------------"<<endl;
	
    for(int i=0;i<row1;++i) {
        delete[] matrix1[i];
    }
    delete[] matrix1;
    
    
    for(int i=0;i<row2;++i) {
        delete[] matrix2[i];
    }
    delete[] matrix2;
    
    
    for(int i=0;i<row1;++i) {
        delete[] result[i];
    }
    delete[] result;
    return 0;
}

