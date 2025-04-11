#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    Complex operator/(const Complex& c) {
        double denom = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denom, (imag * c.real - real * c.imag) / denom);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << "(" << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i)";
        else
            out << " - " << -c.imag << "i)";
        return out;
    }

    friend double magnitude(const Complex& c) {
        return sqrt(c.real * c.real + c.imag * c.imag);
    }
};

int main() {
    Complex a(3, 4);
    Complex b(1, -2);

    Complex sum = a + b;
    Complex diff = a - b;
    Complex prod = a * b;
    Complex quot = a / b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Quotient: " << quot << endl;
    cout << "Magnitude of a: " << magnitude(a) << endl;
    cout << "Magnitude of b: " << magnitude(b) << endl;

    return 0;
}
