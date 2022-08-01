//
// Created by roman on 09.07.2022.
//
#include "CppMatrix.h"

void S21Matrix::MulMatrix(const S21Matrix &other) {
  NullCheck(other);
//  A->columns != B->rows
  if (_cols != other._rows) throw std::invalid_argument("Matrix size mismatch");

  S21Matrix buff(*this);
  int old_cols = _cols;
  RemoveMatrix();
  _rows = buff._rows; _cols = other._cols;
  PointerAllocated();
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < other._cols; ++j) {
      for (int k = 0; k < old_cols; ++k) {
        CheckOverUnderFlow(buff._matrix[i][k] * other._matrix[k][j]);
        _matrix[i][j] += buff._matrix[i][k] * other._matrix[k][j];
      }
    }
  }
}
