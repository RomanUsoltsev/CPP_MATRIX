//
// Created by roman on 09.07.2022.
//
#include "CppMatrix.h"

double S21Matrix::Determinant() {
  double det = 0;
  NullCheck(*this);
  CheckSquareMatrix();
//  S21Matrix buff(*this);
  det = MatrixDet(*this);
  return det;
}

void S21Matrix::CheckSquareMatrix() const {
  if (_rows != _cols) throw std::invalid_argument("Matrix is not square");
}

double S21Matrix::MatrixDet(const S21Matrix &oth) {
  double det = 0;
  int degree = 1;
  if (oth._rows == 1) {
    return oth._matrix[0][0];
  } else if (oth._rows == 2) {
    return oth._matrix[0][0] * oth._matrix[1][1] - oth._matrix[0][1] * oth._matrix[1][0];
  } else {
    S21Matrix new_oth(oth._rows - 1, oth._rows - 1);

    for (int j = 0; j < oth._rows; j++) {
      MatrixMinor(oth, 0, j, new_oth);
      det = det + (degree * oth._matrix[0][j] * MatrixDet(new_oth));
      degree = -degree;
    }
  }
  return det;
}

void S21Matrix::MatrixMinor(const S21Matrix &oth, int rows, int columns, const S21Matrix &new_oth) {
  int offsetRow = 0;
  int offsetCol = 0;
  for (int i = 0; i < new_oth._rows; i++) {
    if (i == rows) { offsetRow = 1; }
    offsetCol = 0;
    for (int j = 0; j < new_oth._rows; j++) {
      if (j == columns) { offsetCol = 1; }
      new_oth._matrix[i][j] = oth._matrix[i + offsetRow][j + offsetCol];
    }
  }
}

