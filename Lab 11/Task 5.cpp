#include <iostream>
#include <exception>

using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template <typename T>
class InventoryItem {
    T stock;
    T maxCapacity;
public:
    InventoryItem(T maxCap) : stock(0), maxCapacity(maxCap) {}

    void setStock(T value) {
        if (value < 0)
            throw NegativeStockException();
        else if (value > maxCapacity)
            throw OverCapacityException();
        stock = value;
    }
};

int main() {
    InventoryItem<int> item(100);

    try {
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5);
    } catch (const NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120);
    } catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

    return 0;
}
