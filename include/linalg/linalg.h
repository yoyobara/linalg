#ifndef LINALG_LINALG_H
#define LINALG_LINALG_H

#include <initializer_list>
#include <vector>
#include "error.h"

using scalar_t = float;

class Matrix2D {
    int rows;
    int columns;
    std::vector<scalar_t> data;

public:
    Matrix2D(int m, int n);
    Matrix2D(std::initializer_list<std::initializer_list<scalar_t>> list);

    scalar_t at(int row, int column) const;

    scalar_t& at(int row, int column);

    Matrix2D operator+(const Matrix2D& other) const;
    Matrix2D operator*(const Matrix2D& other) const;

private:
    void assert_bounds(int m, int n) const;
};

#endif // LINALG_LINALG_H
