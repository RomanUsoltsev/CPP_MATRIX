//
// Created by roman on 09.07.2022.
//
#include "CppMatrix.h"
void S21Matrix::SumMatrix(const S21Matrix& other) {
  SubSumMatrix(other, SUM);
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  SubSumMatrix(other, SUB);
}

void S21Matrix::SubSumMatrix(const S21Matrix &other, int flag) {
  NullCheck(other);
  if (!CheckSizeMatrix(other))
    throw std::out_of_range("Incorrect input, matrices should have the same size");

  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      if (flag == SUM) {
        CheckOverUnderFlow(_matrix[i][j] + other._matrix[i][j]);
        _matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
      }
      if (flag == SUB) {
        CheckOverUnderFlow(_matrix[i][j] - other._matrix[i][j]);
        _matrix[i][j] = _matrix[i][j] - other._matrix[i][j];
      }
    }
  }
}
