#include <iostream>
using namespace std;

class Vector2D {
private:
    float x, y;

public:
    Vector2D(float x = 0, float y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    friend float dotProduct(const Vector2D& v1, const Vector2D& v2);
    friend ostream& operator<<(ostream& os, const Vector2D& v);
};

float dotProduct(const Vector2D& v1, const Vector2D& v2) {
    return (v1.x * v2.x + v1.y * v2.y);
}

ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    Vector2D sum = v1 + v2;
    Vector2D diff = v1 - v2;
    Vector2D scaled = v1 * 2.5;
    float dot = dotProduct(v1, v2);

    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Scaled (v1 * 2.5): " << scaled << endl;
    cout << "Dot Product: " << dot << endl;

    return 0;
}
