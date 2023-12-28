#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    double** data;

    void allocateMemory() {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;
            }
        }
    }

    void deallocateMemory() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

public:

    Matrix(int i, int j) : rows(i), cols(j) {
        allocateMemory();
    }

    Matrix(int i, int j, double* arr) : rows(i), cols(j) {
        allocateMemory();
        for (int k = 0; k < rows; ++k) {
            for (int l = 0; l < cols; ++l) {
                data[k][l] = arr[k * cols + l];
            }
        }
    }

    // Конструктор копирования
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Деструктор
    ~Matrix() {
        deallocateMemory();
    }

    // Перегрузка оператора сложения (+) для матриц
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrices have different dimensions, cannot perform addition." << std::endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Перегрузка оператора умножения (*) для матриц
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            std::cerr << "Number of columns in first matrix should be equal to number of rows in second matrix." << std::endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Остальные методы класса Matrix
    void print() const {
        std::cout << "Matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void input() {
        std::cout << "Enter number of rows: ";
        std::cin >> rows;
        std::cout << "Enter number of columns: ";
        std::cin >> cols;

        deallocateMemory();
        allocateMemory();

        std::cout << "Enter matrix elements:" << std::endl;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                std::cin >> data[row][col];
            }
        }
    }
};

int main() {
    int choice;
    Matrix m1(2, 2);
    Matrix m2(2, 2);

    do {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Input matrices" << std::endl;
        std::cout << "2. Print matrices" << std::endl;
        std::cout << "3. Sum matrices" << std::endl;
        std::cout << "4. Multiply matrices" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter matrix 1:" << std::endl;
                m1.input();
                std::cout << "Enter matrix 2:" << std::endl;
                m2.input();
                break;
            case 2:
                std::cout << "Matrix 1:" << std::endl;
                m1.print();
                std::cout << "Matrix 2:" << std::endl;
                m2.print();
                break;
            case 3: {
                Matrix sumResult = m1 + m2;
                std::cout << "Sum of matrices:" << std::endl;
                sumResult.print();
                break;
            }
            case 4: {
                Matrix multResult = m1 * m2;
                std::cout << "Product of matrices:" << std::endl;
                multResult.print();
                break;
            }
            case 0:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please enter again." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
