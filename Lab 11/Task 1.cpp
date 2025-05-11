#include <iostream>
#include <sstream>
#include <exception>
using namespace std;

class DimensionMismatchException : public exception {
    string message;
public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        stringstream ss;
        ss << "DimensionMismatchException - Matrices must have same dimensions ("
           << r1 << "x" << c1 << " vs " << r2 << "x" << c2 << ")!";
        message = ss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    void input() {
        cout << "Enter elements of " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> data[i][j];
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    Matrix<T> add(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];

        return result;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        cout << "Matrix A:\n";
        A.input();

        cout << "Matrix B:\n";
        B.input();

        Matrix<int> C = A.add(B);
        cout << "Result of A + B:\n";
        C.display();
    }
    catch (const DimensionMismatchException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
