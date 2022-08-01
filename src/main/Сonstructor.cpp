//
// Created by roman on 10.07.2022.
//
#include "CppMatrix.h"

S21Matrix::S21Matrix() {
  PointerAllocated();
}

S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
  PointerAllocated();
}

void S21Matrix::PointerAllocated() {
  if (_rows < 1 || _cols < 1) throw std::invalid_argument("Wrong matrix size");
  _matrix = new double*[_rows];
  for (int i = 0; i < _rows; i++) {
    _matrix[i] = new double[_cols]();
    for (int j = 0; j < _cols; ++j) {
      _matrix[i][j] = 0;
    }
  }
}

void S21Matrix::RemoveMatrix() {
  if (_matrix) {
    for (int i = 0; i < _rows; i++) {
      delete[] _matrix[i];
    }
    delete[] _matrix;
  }
  _rows = 0;
  _cols = 0;
  _matrix = nullptr;
}

S21Matrix::S21Matrix(const S21Matrix& other) : S21Matrix(other._rows, other._cols) {
  if (this != &other)
    CopyMatrix(other);
}

void S21Matrix::CopyMatrix(const S21Matrix &other) {
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _cols; ++j) {
      this->_matrix[i][j] = other._matrix[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  this->_rows = other._rows;
  this->_cols = other._cols;
  this->_matrix = other._matrix;
  other._matrix = nullptr;
  other._rows = 0;
  other._cols = 0;
}

S21Matrix::~S21Matrix() {
  RemoveMatrix();
}
