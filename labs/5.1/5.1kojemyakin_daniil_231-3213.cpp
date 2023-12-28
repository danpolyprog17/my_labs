#include <iostream>

class Matrix {
private:
    int rows;
    int columns;
    double** elements;

public:
    Matrix(int rows, int columns) : rows(rows), columns(columns) {
        elements = new double*[rows];
        for (int i = 0; i < rows; ++i) {
            elements[i] = new double[columns];
            for (int j = 0; j < columns; ++j) {
                elements[i][j] = 0.0;
            }
        }
    }

    Matrix* sum(const Matrix* mat2) const {
        if (this->rows != mat2->getRows() || this->columns != mat2->getColumns()) {
            std::cout << "Matrices should have the same dimensions for addition." << std::endl;
            return nullptr;
        }

        Matrix* result = new Matrix(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                result->setElem(i, j, this->getElem(i, j) + mat2->getElem(i, j));
            }
        }
        return result;
    }

    Matrix* mult(const Matrix* mat2) const {
        if (this->columns != mat2->getRows()) {
            std::cout << "Number of columns in the first matrix should be equal to the number of rows in the second matrix for multiplication." << std::endl;
            return nullptr;
        }

        Matrix* result = new Matrix(this->rows, mat2->getColumns());
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < mat2->getColumns(); ++j) {
                double sum = 0.0;
                for (int k = 0; k < this->columns; ++k) {
                    sum += this->getElem(i, k) * mat2->getElem(k, j);
                }
                result->setElem(i, j, sum);
            }
        }
        return result;
    }

    double trace() const {
        if (this->rows != this->columns) {
            std::cout << "Trace is only defined for square matrices." << std::endl;
            return 0.0;
        }

        double traceSum = 0.0;
        for (int i = 0; i < this->rows; ++i) {
            traceSum += this->getElem(i, i);
        }
        return traceSum;
    }


    Matrix* mult_by_num(double num) const {
        Matrix* result = new Matrix(this->rows, this->columns);
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->columns; ++j) {
                result->setElem(i, j, this->getElem(i, j) * num);
            }
        }
        return result;
    }

    void input() {
        std::cout << "Enter matrix elements:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                std::cin >> elements[i][j];
            }
        }
    }

    void print() const {
        std::cout << "Matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                std::cout << elements[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    int getColumns() const {
        return columns;
    }

    int getRows() const {
        return rows;
    }

    double getElem(int i, int j) const {
        return elements[i][j];
    }

    void setElem(int i, int j, double value) {
        elements[i][j] = value;
    }


    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] elements[i];
        }
        delete[] elements;
    }
};

void printMenu() {
    std::cout << "\nMatrix Operations Menu:" << std::endl;
    std::cout << "1. Addition of Matrices" << std::endl;
    std::cout << "2. Multiplication of Matrices" << std::endl;
    std::cout << "3. Trace of Matrix" << std::endl;
    std::cout << "4. Multiply Matrix by a Number" << std::endl;
    std::cout << "5. Print Matrix" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    int rows, cols;
    std::cout << "Enter number of rows and columns for matrix: ";
    std::cin >> rows >> cols;

    Matrix matrix1(rows, cols);
    matrix1.input();

    int choice;
    do {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Addition of Matrices
                Matrix matrix2(rows, cols);
                matrix2.input();
                Matrix* result = matrix1.sum(&matrix2);
                if (result != nullptr) {
                    std::cout << "Result of Addition:" << std::endl;
                    result->print();
                    delete result;
                }
                break;
            }
            case 2: {
                // Multiplication of Matrices
                int rows2, cols2;
                std::cout << "Enter number of rows and columns for second matrix: ";
                std::cin >> rows2 >> cols2;

                Matrix matrix2(rows2, cols2);
                matrix2.input();
                Matrix* result = matrix1.mult(&matrix2);
                if (result != nullptr) {
                    std::cout << "Result of Multiplication:" << std::endl;
                    result->print();
                    delete result;
                }
                break;
            }
            case 3: {
                // Trace of Matrix
                double trace = matrix1.trace();
                std::cout << "Trace of the Matrix: " << trace << std::endl;
                break;
            }
            case 4: {
                // Multiply Matrix by a Number
                double num;
                std::cout << "Enter the number to multiply the matrix by: ";
                std::cin >> num;

                Matrix* result = matrix1.mult_by_num(num);
                if (result != nullptr) {
                    std::cout << "Result of Multiplication by Number:" << std::endl;
                    result->print();
                    delete result;
                }
                break;
            }
            case 5: {
                // Print Matrix
                matrix1.print();
                break;
            }
            case 6: {
                // Exit
                std::cout << "Exiting program..." << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
