//
// Created by roman on 09.07.2022.
//

#ifndef SRC_MAIN_CPPMATRIX_H_
#define SRC_MAIN_CPPMATRIX_H_

#include <iostream>
#include <cstring>
#include <cassert>
#include <limits>
class S21Matrix {
 private:
  const int DEFAULT_VALUE = 2;
  const double epsilon  = 1e-7;
  const int SUM = 0;
  const int SUB = 1;

 private:
  int _rows = DEFAULT_VALUE, _cols = DEFAULT_VALUE;
  double **_matrix = nullptr;

 public:
// Constructors and destructors
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

// Operators
  double& operator()(int row, int col);
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(double num);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(double num) const;
  friend S21Matrix operator*(double num, const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);

// Main functions
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

// Get Set
  int GetRows() const;
  int GetCols() const;
  double GetEl(int rows, int cols);
  void SetRows(int rows);
  void SetCols(int cols);
  void SetRowsCols(int rows, int cols);

// Secondary functions
 private:
  void PointerAllocated();
  void RemoveMatrix();
  void CopyMatrix(const S21Matrix &other);
  bool CheckSizeMatrix(const S21Matrix &other) const;
  bool CheckMatrixNumbers(const S21Matrix &other);
  void NullCheck(const S21Matrix &other) const;
  void SubSumMatrix(const S21Matrix& other, int flag);
  static double MyFabs(double num);
  void CheckSquareMatrix() const;
  double MatrixDet(const S21Matrix &oth);
  static void MatrixMinor(const S21Matrix &oth, int rows, int columns, const S21Matrix &new_oth);
  void CheckGetEl(int i_row, int i_col) const;

  void MatrixChangeSize(int rows, int cols);
  static int SignPower(int row_i, int col_j);
  static void CheckOverUnderFlow(const double &lc);
};

#endif  // SRC_MAIN_CPPMATRIX_H_
