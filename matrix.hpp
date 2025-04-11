#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    int size;

public:
    // Basic square matrix constructor
    Matrix(int n) : size(n), data(n, std::vector<T>(n)) {}

    // Constructor from 2D vector
    Matrix(const std::vector<std::vector<T>>& values) {
        size = values.size();
        data = values;
    }

    // Getters
    int getSize() const { return size; }
    int get_size() const { return size; }

    // Access
    std::vector<T>& operator[](int index) { return data[index]; }
    const std::vector<T>& operator[](int index) const { return data[index]; }

    T get_value(int row, int col) const {
        if (row < 0 || row >= size || col < 0 || col >= size)
            throw std::out_of_range("Index out of range");
        return data[row][col];
    }

    void set_value(int row, int col, T value) {
        if (row < 0 || row >= size || col < 0 || col >= size)
            throw std::out_of_range("Index out of range");
        data[row][col] = value;
    }

    // Output
    void print() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                std::cout << std::setw(8) << static_cast<double>(val);
            std::cout << std::endl;
        }
    }

    // Operator Overloads
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

    // Diagonal sums
    T sum_diagonal_major() const {
        T sum = 0;
        for (int i = 0; i < size; ++i)
            sum += data[i][i];
        return sum;
    }

    T sum_diagonal_minor() const {
        T sum = 0;
        for (int i = 0; i < size; ++i)
            sum += data[i][size - 1 - i];
        return sum;
    }

    // Swap operations
    void swap_rows(int i, int j) {
        if (i < 0 || j < 0 || i >= size || j >= size)
            throw std::out_of_range("Index out of range");
        std::swap(data[i], data[j]);
    }

    void swap_cols(int i, int j) {
        if (i < 0 || j < 0 || i >= size || j >= size)
            throw std::out_of_range("Index out of range");
        for (int r = 0; r < size; ++r)
            std::swap(data[r][i], data[r][j]);
    }
};

#endif
