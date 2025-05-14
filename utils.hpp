#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

template<typename T>
void swapRows(std::vector<T>& row1, std::vector<T>& row2) {
    std::swap(row1, row2);
}

template<typename T>
void swapCols(std::vector<std::vector<T>>& matrix, int col1, int col2) {
    int n = matrix.size();
    if (col1 >= n || col2 >= n || col1 < 0 || col2 < 0)
        throw std::out_of_range("Column index out of range");
    for (int i = 0; i < n; ++i)
        std::swap(matrix[i][col1], matrix[i][col2]);
}

template<typename T>
void updateElement(std::vector<std::vector<T>>& matrix, int row, int col, T newVal) {
    if (row >= matrix.size() || col >= matrix[0].size() || row < 0 || col < 0)
        throw std::out_of_range("Indices out of range");
    matrix[row][col] = newVal;
}

#endif


// Polymorphic swap function
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
