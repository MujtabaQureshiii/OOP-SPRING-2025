#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string productID;
    string productName;
    double price;
    int stockQuantity;
public:
    Product(string id, string name, double p, int qty) {
        productID = id;
        productName = name;
        price = p;
        stockQuantity = qty;
    }

    virtual double applyDiscount() {
        return price;
    }

    virtual double calculateTotalPrice(int quantity) {
        return applyDiscount() * quantity;
    }

    virtual void displayProductInfo() {
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stockQuantity << endl;
    }

    friend ostream& operator<<(ostream& out, Product& p) {
        p.displayProductInfo();
        return out;
    }

    Product operator+(Product& other) {
        return Product("BULK", "BulkProduct", this->price + other.price, 0);
    }
};

class Electronics : public Product {
    int warrantyPeriod;
    string brand;
public:
    Electronics(string id, string name, double p, int qty, int wp, string b)
        : Product(id, name, p, qty), warrantyPeriod(wp), brand(b) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Brand: " << brand << endl;
        cout << "Warranty: " << warrantyPeriod << " months" << endl;
    }
};

class Clothing : public Product {
    string size;
    string color;
    string fabricMaterial;
public:
    Clothing(string id, string name, double p, int qty, string s, string c, string f)
        : Product(id, name, p, qty), size(s), color(c), fabricMaterial(f) {}

    double applyDiscount() override {
        return price * 0.9;
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;
public:
    FoodItem(string id, string name, double p, int qty, string ed, int cal)
        : Product(id, name, p, qty), expirationDate(ed), calories(cal) {}

    double calculateTotalPrice(int quantity) override {
        if (quantity > 10)
            return price * quantity * 0.85;
        return price * quantity;
    }
};

class Book : public Product {
    string author;
    string genre;
public:
    Book(string id, string name, double p, int qty, string a, string g)
        : Product(id, name, p, qty), author(a), genre(g) {}

    void displayProductInfo() override {
        Product::displayProductInfo();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Electronics e("E101", "Smartphone", 50000, 10, 24, "Samsung");
    Clothing c("C202", "T-Shirt", 1500, 30, "M", "Black", "Cotton");
    FoodItem f("F303", "Biryani Masala Pack", 300, 50, "2025-01-01", 200);
    Book b("B404", "C++ Guide", 1200, 15, "Bjarne Stroustrup", "Programming");

    cout << e << endl;
    cout << c << endl;
    cout << f << endl;
    cout << b << endl;

    Product bulk = c + b;
    cout << "Bulk Product Price: " << bulk.calculateTotalPrice(1) << endl;

    cout << "Clothing Total (5): " << c.calculateTotalPrice(5) << endl;
    cout << "Food Total (12): " << f.calculateTotalPrice(12) << endl;

    return 0;
}
