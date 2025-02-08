#include <iostream>
#include <string>
using namespace std;

int main() {
    int size,sum = 0;
    cout<<"Enter the Size of the Array: ";
    cin>>size;
    int*array = new int[size];
    cout<<"Enter the element in the array\n";

    for(int i=0;i<size;i++){
        cout<<"Element No "<<i+1<<": ";
        cin>>*(array+i);
        sum+=*(array+i);
    }
    cout<<"The sum of the array is: "<<sum;
    delete []array;
    return 0;
}
