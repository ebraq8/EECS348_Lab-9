#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    int size;

public:
    Matrix(int n) : size(n), data(n, std::vector<T>(n)) {}

    void set(int row, int col, T value) {
        data[row][col] = value;
    }

    T get(int row, int col) const {
        return data[row][col];
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                std::cout << std::setw(8) << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        Matrix<T> result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                for (int k = 0; k < size; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    T diagonalSum(bool mainDiagonal) const {
        T sum = 0;
        for (int i = 0; i < size; ++i) {
            if (mainDiagonal)
                sum += data[i][i];
            else
                sum += data[i][size - 1 - i];
        }
        return sum;
    }

    void swapCols(int col1, int col2) {
        for (int i = 0; i < size; ++i)
            std::swap(data[i][col1], data[i][col2]);
    }

    void swapRows(int row1, int row2) {
        std::swap(data[row1], data[row2]);
    }

    void updateElement(int row, int col, T newVal) {
        data[row][col] = newVal;
    }

    int getSize() const {
        return size;
    }

    std::vector<std::vector<T>>& getData() {
        return data;
    }
};

#endif // MATRIX_HPP

