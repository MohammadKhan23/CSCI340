#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <cassert>

// Constructor
matrix::matrix(unsigned int rows, unsigned int cols) {
    resize(rows, cols);
}

// Resize method
void matrix::resize(unsigned int rows, unsigned int cols) {
    mat.resize(rows);
    for (auto &row : mat) {
        row.resize(cols);
    }
}

// Load matrix from input stream
void matrix::load(std::istream &is) {
    unsigned int rows, cols;
    is >> rows >> cols;
    resize(rows, cols);
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            is >> mat[i][j];
        }
    }
}

// Print matrix with specified column width
void matrix::print(int colWidth) const {
    for (unsigned int i = 0; i < getRows(); ++i) {
        for (unsigned int j = 0; j < getCols(); ++j) {
            std::cout << std::setw(colWidth) << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Matrix multiplication
matrix matrix::operator*(const matrix &rhs) const {
    assert(getCols() == rhs.getRows());
    matrix result(getRows(), rhs.getCols());
    for (unsigned int i = 0; i < getRows(); ++i) {
        for (unsigned int j = 0; j < rhs.getCols(); ++j) {
            result.at(i, j) = 0;
            for (unsigned int k = 0; k < getCols(); ++k) {
                result.at(i, j) += at(i, k) * rhs.at(k, j);
            }
        }
    }
    return result;
}
