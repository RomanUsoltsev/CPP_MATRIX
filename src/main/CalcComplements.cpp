//
// Created by roman on 09.07.2022.
//
#include "CppMatrix.h"

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix new_matrix(_rows, _cols);
  NullCheck(*this);
  CheckSquareMatrix();
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      int degree = SignPower(i, j);
      S21Matrix minor(_rows - 1, _cols - 1);
      MatrixMinor(*this, i, j, minor);
      double det_minor = minor.Determinant();
      new_matrix._matrix[i][j] = degree * det_minor;
    }
  }


  return new_matrix;
}

int S21Matrix::SignPower(int row_i, int col_j) {
  int sign = 1;
  if ((row_i + col_j) % 2 != 0) {sign = -sign;}
  return sign;
}
