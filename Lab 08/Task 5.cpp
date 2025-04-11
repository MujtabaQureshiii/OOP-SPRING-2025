#include <iostream>
using namespace std;

class Matrix2x2;

class MatrixHelper {
public:
    void updateElement(Matrix2x2& m, int row, int col, int value);
};

class Matrix2x2 {
private:
    int m[2][2];

public:
    Matrix2x2(int a, int b, int c, int d) {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }

    Matrix2x2 operator+(const Matrix2x2& other) {
        return Matrix2x2(
            m[0][0] + other.m[0][0], m[0][1] + other.m[0][1],
            m[1][0] + other.m[1][0], m[1][1] + other.m[1][1]
        );
    }

    Matrix2x2 operator-(const Matrix2x2& other) {
        return Matrix2x2(
            m[0][0] - other.m[0][0], m[0][1] - other.m[0][1],
            m[1][0] - other.m[1][0], m[1][1] - other.m[1][1]
        );
    }

    Matrix2x2 operator*(const Matrix2x2& other) {
        return Matrix2x2(
            m[0][0]*other.m[0][0] + m[0][1]*other.m[1][0],
            m[0][0]*other.m[0][1] + m[0][1]*other.m[1][1],
            m[1][0]*other.m[0][0] + m[1][1]*other.m[1][0],
            m[1][0]*other.m[0][1] + m[1][1]*other.m[1][1]
        );
    }

    friend int determinant(const Matrix2x2& m);
    friend class MatrixHelper;

    friend ostream& operator<<(ostream& out, const Matrix2x2& m) {
        out << m.m[0][0] << " " << m.m[0][1] << endl;
        out << m.m[1][0] << " " << m.m[1][1];
        return out;
    }
};

void MatrixHelper::updateElement(Matrix2x2& mtx, int row, int col, int value) {
    if (row >= 0 && row < 2 && col >= 0 && col < 2)
        mtx.m[row][col] = value;
}

int determinant(const Matrix2x2& m) {
    return m.m[0][0]*m.m[1][1] - m.m[0][1]*m.m[1][0];
}

int main() {
    Matrix2x2 A(1, 2, 3, 4);
    Matrix2x2 B(5, 6, 7, 8);

    cout << "Matrix A:\n" << A << "\n\n";
    cout << "Matrix B:\n" << B << "\n\n";

    Matrix2x2 C = A + B;
    cout << "A + B:\n" << C << "\n\n";

    Matrix2x2 D = A - B;
    cout << "A - B:\n" << D << "\n\n";

    Matrix2x2 E = A * B;
    cout << "A * B:\n" << E << "\n\n";

    cout << "Determinant of A: " << determinant(A) << "\n\n";

    MatrixHelper helper;
    helper.updateElement(A, 0, 1, 10);
    cout << "Matrix A after update:\n" << A << endl;

    return 0;
}
