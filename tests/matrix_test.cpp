#include "linalg/linalg.h"
#include <gtest/gtest.h>

TEST(MatrixTest, indexing) {
    Matrix2D mat(3, 2);

    ASSERT_THROW(mat.at(5, 5), MatrixException);
    ASSERT_THROW(mat.at(-2, -2), MatrixException);

    ASSERT_THROW(mat.at(3, 0), MatrixException);
    ASSERT_THROW(mat.at(-1, 0), MatrixException);

    ASSERT_THROW(mat.at(0, -1), MatrixException);
    ASSERT_THROW(mat.at(0, 2), MatrixException);

    ASSERT_NO_THROW(mat.at(0, 1));
    ASSERT_NO_THROW(mat.at(2, 0));

    ASSERT_NO_THROW(mat.at(0, 0));
}
