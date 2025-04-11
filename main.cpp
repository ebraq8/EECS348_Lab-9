#include "Matrix.hpp"
#include "utils.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./matrix <filename>\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Error: Cannot open file.\n";
        return 1;
    }

    int n, typeFlag;
    infile >> n >> typeFlag;

    if (typeFlag == 0) {
        Matrix<int> m1(n), m2(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                infile >> m1[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                infile >> m2[i][j];

        std::cout << "Matrix A:\n"; m1.print();
        std::cout << "Matrix B:\n"; m2.print();

        Matrix<int> sum = m1 + m2;
        std::cout << "A + B:\n"; sum.print();

        Matrix<int> product = m1 * m2;
        std::cout << "A * B:\n"; product.print();

        std::cout << "Main diagonal sum of A: " << m1.diagonalSum(true) << std::endl;
        std::cout << "Secondary diagonal sum of A: " << m1.diagonalSum(false) << std::endl;

        std::cout << "Swapping rows 0 and 1 in A:\n";
        swapRows(m1[0], m1[1]); m1.print();

        std::cout << "Swapping columns 0 and 1 in A:\n";
        swapCols(m1, 0, 1); m1.print();

        std::cout << "Updating A[0][0] to 100:\n";
        updateElement(m1, 0, 0, 100); m1.print();

    } else {
        Matrix<double> m1(n), m2(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                infile >> m1[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                infile >> m2[i][j];

        std::cout << "Matrix A:\n"; m1.print();
        std::cout << "Matrix B:\n"; m2.print();

        Matrix<double> sum = m1 + m2;
        std::cout << "A + B:\n"; sum.print();

        Matrix<double> product = m1 * m2;
        std::cout << "A * B:\n"; product.print();

        std::cout << "Main diagonal sum of A: " << m1.diagonalSum(true) << std::endl;
        std::cout << "Secondary diagonal sum of A: " << m1.diagonalSum(false) << std::endl;

        std::cout << "Swapping rows 0 and 1 in A:\n";
        swapRows(m1[0], m1[1]); m1.print();

        std::cout << "Swapping columns 0 and 1 in A:\n";
        swapCols(m1, 0, 1); m1.print();

        std::cout << "Updating A[0][0] to 100.5:\n";
        updateElement(m1, 0, 0, 100.5); m1.print();
    }

    return 0;
}