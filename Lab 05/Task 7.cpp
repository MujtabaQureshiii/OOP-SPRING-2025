#include <iostream>
using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;
    
    Product() : id(0), name(""), quantity(0) {}
    Product(int i, string n, int q) : id(i), name(n), quantity(q) {}
    
    void display() const {
        cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Quantity: " << quantity << endl;
    }
};

class Warehouse {
private:
    Product products[5]; 
    int pCount;
public:
    Warehouse() : pCount(0) {}
    
    void addProduct(int id, string name, int quantity) {
        if (pCount < 5) {
            products[pCount] = Product(id, name, quantity);
            pCount++;
        } else {
            cout << "Inventory is full"<<endl;
        }
    }
    
    void sortProductsAlphabetically() {
        for (int i = 0; i < pCount - 1; i++) {
            for (int j = i + 1; j < pCount; j++) {
                if (products[i].name > products[j].name) {
                    swap(products[i], products[j]);
                }
            }
        }
    }
    
    void searchProductByID(int searchID) const {
        for (int i = 0; i < pCount; i++) {
            if (products[i].id == searchID) {
                cout << "Product Found:\n";
                products[i].display();
                return;
            }
        }
        cout << "Product not found!\n";
    }
    
    void displayInventory() const {
        cout << "\nWarehouse Inventory:\n";
        cout << "------------------------------" << endl;
        for (int i = 0; i < pCount; i++) {
            products[i].display();
            cout << "------------------------------" << endl;
        }
    }
};

int main() {
    Warehouse warehouse;
    
    warehouse.addProduct(1, "Laptop", 10);
    warehouse.addProduct(2, "Chair", 30);
    warehouse.addProduct(3, "Table", 25);
    
    warehouse.sortProductsAlphabetically();
    warehouse.displayInventory();
    
    cout << "\nSearching for product with ID 2:\n";
    warehouse.searchProductByID(2);
    
    return 0;
}
