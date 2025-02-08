#include <iostream>
using namespace std;

struct Product {
    int productID;
    string name;
    int quantity;
    double price;
};

double TotalValue(Product*products, int num) {
    double totalValue = 0;
    for (int i = 0; i < num; i++) {
    totalValue += products[i].quantity * products[i].price;
    }
    return totalValue;
}

int main() {
    int num;
    cout<<"Enter the No of products: "; 
	cin>>num;
    Product* products = new Product[num];

    for (int i = 0; i < num; i++) {
        cout<<"\nDetail Of Product No "<<i+1<<":\n";
        cout<<"ID: "; 
        cin>>products[i].productID;
        cin.ignore();
        cout<<"Name: "; 
        getline(cin, products[i].name);
        cout<<"Quantity: "; 
        cin>>products[i].quantity;
        cout<<"Price: "; 
        cin>>products[i].price;
    }

    cout<<"\nTOTAL VALUE OF INVENTORY: "<<TotalValue(products, num)<<" $"<<endl;
    delete[] products;
    return 0;
}
