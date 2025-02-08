#include <iostream>
using namespace std;

int main() {
    int num;
    cout<<"Enter size of array: ";
    cin>>num;
    int** arr=new int*[num];
    for(int i=0;i<num;i++) {
        arr[i]=new int;
        cout<<"Enter element No "<<i+1<<": ";
        cin>>*arr[i];
    }

    cout<<"\nArray elements: ";
    cout<<"[ ";
    for(int i=0;i<num;i++) {
        cout<<*arr[i]<<" ";
    }
    cout<<"]";
    cout<<endl;
    for(int i=0;i<num;i++) {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}
