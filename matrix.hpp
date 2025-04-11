#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    int size;

public:
    Matrix(int n) : size(n), data(n, std::vector<T>(n)) {}

    int getSize() const { return size; }

    std::vector<T>& operator[](int index) { return data[index]; }
    const std::vector<T>& operator[](int index) const { return data[index]; }

    void print() const {
        for (const auto& row : data) {
            for (const auto& val : row) {
                std::cout << std::setw(8) << static_cast<double>(val);
            }
            std::cout << std::endl;
        }
    }

    friend Matrix<T> operator+(const Matrix<T>& a, const Matrix<T>& b) {
        if (a.size != b.size) throw std::invalid_argument("Matrix sizes must match");
        Matrix<T> result(a.size);
        for (int i = 0; i < a.size; ++i)
            for (int j = 0; j < a.size; ++j)
                result[i][j] = a[i][j] + b[i][j];
        return result;
    }

    friend Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b) {
        if (a.size != b.size) throw std::invalid_argument("Matrix sizes must match");
        Matrix<T> result(a.size);
        for (int i = 0; i < a.size; ++i)
            for (int j = 0; j < a.size; ++j)
                for (int k = 0; k < a.size; ++k)
                    result[i][j] += a[i][k] * b[k][j];
        return result;
    }

    T diagonalSum(bool mainDiagonal = true) const {
        T sum = 0;
        for (int i = 0; i < size; ++i)
            sum += mainDiagonal ? data[i][i] : data[i][size - 1 - i];
        return sum;
    }

    // ✅ This is the missing method the tests need
    T get_value(int row, int col) const {
        if (row < 0 || row >= size || col < 0 || col >= size)
            throw std::out_of_range("Index out of range");
        return data[row][col];
    }
};

#endif
