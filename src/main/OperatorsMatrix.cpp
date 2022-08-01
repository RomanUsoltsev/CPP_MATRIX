//
// Created by roman on 10.07.2022.
//
#include "CppMatrix.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix res(*this);
    res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix res(*this);
    res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix res(*this);
    res.MulMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix res(*this);
    res.MulNumber(num);
  return res;
}

double &S21Matrix::operator()(int row, int col) {
  NullCheck(*this);
  CheckGetEl(row, col);
  return _matrix[row][col];
}

void S21Matrix::CheckGetEl(int i_row, int i_col) const {
  if (i_row > (_rows - 1) || i_row < 0 || i_col > (_cols - 1) || i_col < 0) {
    throw std::invalid_argument("Invalid index");
  }
}

int S21Matrix::GetRows() const {
  return _rows;
}
int S21Matrix::GetCols() const {
  return _cols;
}

void S21Matrix::SetRows(int rows) {
  if (rows < 1) throw std::invalid_argument("Invalid row size");
  MatrixChangeSize(rows, 0);
}

void S21Matrix::SetCols(int cols) {
  if (cols < 1) throw std::invalid_argument("Invalid column size");
  MatrixChangeSize(0, cols);
}

void S21Matrix::SetRowsCols(int rows, int cols) {
  SetRows(rows);
  SetCols(cols);
}

void S21Matrix::MatrixChangeSize(int rows, int cols) {
  S21Matrix buff(*this);
  int new_rows = rows > 0 ? rows : _rows;
  int new_cols = cols > 0 ? cols : _cols;
  RemoveMatrix();
  _rows = new_rows;
  _cols = new_cols;
  PointerAllocated();
  int copy_i = new_rows > buff._rows ? buff._rows : new_rows;
  int copy_j = new_cols > buff._cols ? buff._cols : new_cols;
  for (int i = 0; i < copy_i; ++i) {
    for (int j = 0; j < copy_j; ++j) {
      _matrix[i][j] = buff._matrix[i][j];
    }
  }
}

double S21Matrix::GetEl(int row, int col) {
  CheckGetEl(row, col);
  return _matrix[row][col];
}

S21Matrix& S21Matrix::operator=(const S21Matrix &other) {
  NullCheck(other);
  if (this != &other) {
    RemoveMatrix();
    _rows = other._rows;
    _cols = other._cols;
    PointerAllocated();
    CopyMatrix(other);
  }
  return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) {
  return EqMatrix(other);
}

void S21Matrix::operator+=(const S21Matrix &other) {
    SumMatrix(other);
}

void S21Matrix::operator-=(const S21Matrix &other) {
    SubMatrix(other);
}

void S21Matrix::operator*=(const S21Matrix &other) {
    MulMatrix(other);
}

void S21Matrix::operator*=(double num) {
    MulNumber(num);
}
S21Matrix operator*(const double num, const S21Matrix &other) {
  S21Matrix res(other);
    res.MulNumber(num);
  return res;
}



