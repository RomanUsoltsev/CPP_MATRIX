//
// Created by roman on 09.07.2022.
//
#include "CppMatrix.h"

S21Matrix S21Matrix::InverseMatrix() {
  CheckSquareMatrix();
  NullCheck(*this);
  double det = Determinant();
  double inverse_det = 1.0f / det;
  if (MyFabs(det) < 1e-8) throw std::invalid_argument("Invalid Determinant value");

  S21Matrix matrix_comp(CalcComplements());
  S21Matrix matrix_comp_transpose(matrix_comp.Transpose());
    matrix_comp_transpose.MulNumber(inverse_det);
  return matrix_comp_transpose;
}
