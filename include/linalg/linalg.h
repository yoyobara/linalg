#ifndef LINALG_LINALG_H
#define LINALG_LINALG_H


template<typename T>
class Matrix2D {
    int rows;
    int columns;
    T* data;

public:
    Matrix2D(int m, int n);
};

#endif // LINALG_LINALG_H
