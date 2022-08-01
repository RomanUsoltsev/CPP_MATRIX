//
// Created by roman on 09.07.2022.
//
#include "CppMatrix.h"

S21Matrix S21Matrix::Transpose() {
  S21Matrix res(_cols, _rows);
  NullCheck(*this);
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      res._matrix[j][i] = _matrix[i][j];
    }
  }
  return res;
}
