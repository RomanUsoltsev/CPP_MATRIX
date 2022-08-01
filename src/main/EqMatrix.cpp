//
// Created by roman on 09.07.2022.
//
#include "CppMatrix.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool flag = true;
  NullCheck(other);
  if (this != &other) {
    flag = CheckSizeMatrix(other);
    if (flag) flag = CheckMatrixNumbers(other);
  }
  return flag;
}

bool S21Matrix::CheckSizeMatrix(const S21Matrix &other) const {
  return _cols == other._cols && _rows == other._rows;
}

bool S21Matrix::CheckMatrixNumbers(const S21Matrix &other) {
  bool flag = true;
  for (int i = 0; i < _rows; ++i && flag) {
    for (int j = 0; j < _cols; ++j && flag) {
      if (MyFabs(_matrix[i][j] - other._matrix[i][j]) > epsilon) {
        flag = false;
      }
    }
  }
  return flag;
}

void S21Matrix::NullCheck(const S21Matrix &other) const {
  if (other._matrix == nullptr || this->_matrix == nullptr)
    throw std::invalid_argument("Null pointer reference");
}

double S21Matrix::MyFabs(double num) {
  return num < 0 ? -num : num;
}
