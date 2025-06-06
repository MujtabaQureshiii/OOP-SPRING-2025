#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("vehicles.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open the file 'vehicles.txt'." << endl;
        return 1;
    }
    string line;
    while (getline(inputFile, line)) {
        if (line.empty() || line.substr(0, 2) == "//") {
            continue;
        }
        cout << line << endl;
    }
    inputFile.close();
    return 0;
}
