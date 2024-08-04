#include "linalg/linalg.h"
#include <cstddef>
#include <strstream>

Matrix2D::Matrix2D(int rows, int columns) : rows(rows), columns(columns), data(rows * columns, 0.0) {}

Matrix2D::Matrix2D(std::initializer_list<std::initializer_list<scalar_t>> list) : rows(list.size()), columns(list.begin()->size()), data(rows * columns) {
    for (auto row : list) {
        for (auto val : row) {
            data.push_back(val);
        }
    }
}

scalar_t Matrix2D::at(int row, int column) const {
    assert_bounds(row, column);
    return data.at(row * this->columns + column);
}

scalar_t& Matrix2D::at(int row, int column) {
    assert_bounds(row, column);
    return data.at(row * this->columns + column);
}

void Matrix2D::assert_bounds(int m, int n) const {
    if (m >= rows || m < 0 || n >= columns || n < 0) {
        std::ostrstream ss;

        ss << "bad index (" << m << ", " << n << 
            ") for matrix of shape (" << rows << ", " << columns << ").";

        throw MatrixException(ss.str());
    }
}

Matrix2D Matrix2D::operator+(const Matrix2D& other) const {
    Matrix2D res_mat(rows, columns);

    if (rows != other.rows || columns != other.columns) {
        std::ostrstream ss;
        
        ss << "matrix addition is undefined for shapes (" << rows << ", " << columns 
            << ") and (" << other.rows << ", " << other.columns << ")";

        throw MatrixException(ss.str());
    }

    for (size_t i = 0 ; i < data.size() ; i++) {
        res_mat.data.at(i) = data.at(i) + other.data.at(i);
    }

    return res_mat;
}

// Matrix2D Matrix2D::operator*(const Matrix2D& other) const {
// }
