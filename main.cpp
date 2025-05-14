#include "matrix.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./matrix <input_file>\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Cannot open file.\n";
        return 1;
    }

    int n, type;
    infile >> n >> type;

    if (type == 0) { // integer matrices
        Matrix<int> m1(n), m2(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int temp; infile >> temp;
                m1.set(i, j, temp);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int temp; infile >> temp;
                m2.set(i, j, temp);
            }
        }

        std::cout << "Matrix A:\n";
        m1.print();
        std::cout << "Matrix B:\n";
        m2.print();

        std::cout << "A + B:\n";
        (m1 + m2).print();

        std::cout << "A * B:\n";
        (m1 * m2).print();

        std::cout << "Main diagonal sum of A: " << m1.diagonalSum(true) << "\n";
        std::cout << "Secondary diagonal sum of A: " << m1.diagonalSum(false) << "\n";

        std::cout << "Swap rows of A:\n";
        m1.swapRows(0, 1); m1.print();

        std::cout << "Swap cols of A:\n";
        m1.swapCols(0, 1); m1.print();

        std::cout << "Update A[0][0] = 100:\n";
        m1.updateElement(0, 0, 100); m1.print();
    } else if (type == 1) { // double matrices
        Matrix<double> m1(n), m2(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                double temp; infile >> temp;
                m1.set(i, j, temp);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                double temp; infile >> temp;
                m2.set(i, j, temp);
            }
        }

        std::cout << "Matrix A:\n";
        m1.print();
        std::cout << "Matrix B:\n";
        m2.print();

        std::cout << "A + B:\n";
        (m1 + m2).print();

        std::cout << "A * B:\n";
        (m1 * m2).print();

        std::cout << "Main diagonal sum of A: " << m1.diagonalSum(true) << "\n";
        std::cout << "Secondary diagonal sum of A: " << m1.diagonalSum(false) << "\n";

        std::cout << "Swap rows of A:\n";
        m1.swapRows(0, 1); m1.print();

        std::cout << "Swap cols of A:\n";
        m1.swapCols(0, 1); m1.print();

        std::cout << "Update A[0][0] = 100.5:\n";
        m1.updateElement(0, 0, 100.5); m1.print();
    }

    return 0;
}

