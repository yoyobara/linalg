#ifndef LINALG_LINALG_H
#define LINALG_LINALG_H


// this class represents a 2D matrix. the type T should support multiplication and addition of a mathematical "field".
template<typename T>
class Matrix2D {
    int rows;
    int columns;
    T* data;

public:
    Matrix2D(int m, int n);
    ~Matrix2D();
};

#endif // LINALG_LINALG_H
