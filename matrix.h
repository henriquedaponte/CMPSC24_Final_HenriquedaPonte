#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <numeric>
#include <vector>

typedef std::vector<int> Array;
typedef std::vector<Array> Matrix;

Matrix matrixAdd(const Matrix & matrix_1, const Matrix & matrix_2);
Matrix matrixMultiply(const Matrix & matrix_1, const Matrix & matrix_2);


#endif