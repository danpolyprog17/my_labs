#include <iostream>

class TridiagonalMatrix {
private:
    int size;
    double* mainDiagonal;
    double* upperDiagonal;
    double* lowerDiagonal;

public:
    TridiagonalMatrix() : size(0), mainDiagonal(nullptr), upperDiagonal(nullptr), lowerDiagonal(nullptr) {}

    TridiagonalMatrix(int n) : size(n) {
        mainDiagonal = new double[n];
        upperDiagonal = new double[n - 1];
        lowerDiagonal = new double[n - 1];
    }

    ~TridiagonalMatrix() {
        delete[] mainDiagonal;
        delete[] upperDiagonal;
        delete[] lowerDiagonal;
    }

    double tr() const {
        double trace = 0.0;
        for (int i = 0; i < size; ++i) {
            trace += mainDiagonal[i];
        }
        return trace;
    }



    // Метод ввода матрицы
    void input() {
        std::cout << "Enter matrix size: ";
        std::cin >> size;

        mainDiagonal = new double[size];
        upperDiagonal = new double[size - 1];
        lowerDiagonal = new double[size - 1];

        std::cout << "Enter main diagonal elements:" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cin >> mainDiagonal[i];
        }

        std::cout << "Enter upper diagonal elements:" << std::endl;
        for (int i = 0; i < size - 1; ++i) {
            std::cin >> upperDiagonal[i];
        }

        std::cout << "Enter lower diagonal elements:" << std::endl;
        for (int i = 0; i < size - 1; ++i) {
            std::cin >> lowerDiagonal[i];
        }
    }

    // Метод печати матрицы
    void print() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i == j) {
                    std::cout << mainDiagonal[i] << " ";
                } else if (j == i + 1) {
                    std::cout << upperDiagonal[i] << " ";
                } else if (j == i - 1) {
                    std::cout << lowerDiagonal[j] << " ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }

    // Получение количества столбцов
    int columns() const {
        return size;
    }

    // Перегрузка оператора ввода >>
    friend std::istream& operator>>(std::istream& is, TridiagonalMatrix& matrix) {
        matrix.input();
        return is;
    }

    // Перегрузка оператора вывода <<
    friend std::ostream& operator<<(std::ostream& os, const TridiagonalMatrix& matrix) {
        matrix.print();
        return os;
    }

    // Перегрузка оператора сложения +
    TridiagonalMatrix operator+(const TridiagonalMatrix& other) const {
        TridiagonalMatrix result(size);
        for (int i = 0; i < size; ++i) {
            result.mainDiagonal[i] = mainDiagonal[i] + other.mainDiagonal[i];
        }
        for (int i = 0; i < size - 1; ++i) {
            result.upperDiagonal[i] = upperDiagonal[i] + other.upperDiagonal[i];
            result.lowerDiagonal[i] = lowerDiagonal[i] + other.lowerDiagonal[i];
        }
        return result;
    }

    // Перегрузка оператора вычитания -
    TridiagonalMatrix operator-(const TridiagonalMatrix& other) const {
        TridiagonalMatrix result(size);
        for (int i = 0; i < size; ++i) {
            result.mainDiagonal[i] = mainDiagonal[i] - other.mainDiagonal[i];
        }
        for (int i = 0; i < size - 1; ++i) {
            result.upperDiagonal[i] = upperDiagonal[i] - other.upperDiagonal[i];
            result.lowerDiagonal[i] = lowerDiagonal[i] - other.lowerDiagonal[i];
        }
        return result;
    }

    // Перегрузка унарного минуса (-)
    TridiagonalMatrix operator-() const {
        TridiagonalMatrix result(size);
        for (int i = 0; i < size; ++i) {
            result.mainDiagonal[i] = -mainDiagonal[i];
        }
        for (int i = 0; i < size - 1; ++i) {
            result.upperDiagonal[i] = -upperDiagonal[i];
            result.lowerDiagonal[i] = -lowerDiagonal[i];
        }
        return result;
    }

    // Перегрузка оператора умножения на число (*)
    TridiagonalMatrix operator*(double scalar) const {
        TridiagonalMatrix result(size);
        for (int i = 0; i < size; ++i) {
            result.mainDiagonal[i] = mainDiagonal[i] * scalar;
        }
        for (int i = 0; i < size - 1; ++i) {
            result.upperDiagonal[i] = upperDiagonal[i] * scalar;
            result.lowerDiagonal[i] = lowerDiagonal[i] * scalar;
        }
        return result;
    }

    // Перегрузка оператора +=
    TridiagonalMatrix& operator+=(const TridiagonalMatrix& other) {
        *this = *this + other;
        return *this;
    }

    // Перегрузка оператора -=
    TridiagonalMatrix& operator-=(const TridiagonalMatrix& other) {
        *this = *this - other;
        return *this;
    }
};

int main() {
    TridiagonalMatrix matrix1, matrix2;
    std::cout << "Enter matrix 1:" << std::endl;
    std::cin >> matrix1;

    std::cout << "Enter matrix 2:" << std::endl;
    std::cin >> matrix2;

    std::cout << "Matrix 1:" << std::endl;
    std::cout << matrix1;

    std::cout << "Matrix 2:" << std::endl;
    std::cout << matrix2;

    TridiagonalMatrix sum = matrix1 + matrix2;
    std::cout << "Sum of matrices:" << std::endl;
    std::cout << sum;

    TridiagonalMatrix difference = matrix1 - matrix2;
    std::cout << "Difference of matrices:" << std::endl;
    std::cout << difference;

    TridiagonalMatrix negation = -matrix1;
    std::cout << "Negation of matrix 1:" << std::endl;
    std::cout << negation;

    double scalar;
    std::cout << "Enter a scalar value:" << std::endl;
    std::cin >> scalar;

    TridiagonalMatrix scalarProduct = matrix1 * scalar;
    std::cout << "Scalar product of matrix 1:" << std::endl;
    std::cout << scalarProduct;

    matrix1 += matrix2;
    std::cout << "Matrix 1 after addition:" << std::endl;
    std::cout << matrix1;

    matrix1 -= matrix2;
    std::cout << "Matrix 1 after subtraction:" << std::endl;
    std::cout << matrix1;

    return 0;
}
