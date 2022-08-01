//
// Created by roman on 09.07.2022.
//

#include "CppMatrix.h"
void S21Matrix::MulNumber(const double num) {
  CheckOverUnderFlow(num);
  NullCheck(*this);
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      CheckOverUnderFlow(_matrix[i][j] * num);
      _matrix[i][j] = _matrix[i][j] * num;
    }
  }
}

void S21Matrix:: CheckOverUnderFlow(const double &lc) {
  if (!(-std::numeric_limits<double>::max() < lc && lc < std::numeric_limits<double>::max()) )
    throw std::invalid_argument("Argument overflow");
  if (-std::numeric_limits<double>::min() < lc && lc < std::numeric_limits<double>::min())
    throw std::invalid_argument("Argument underflow");
}
