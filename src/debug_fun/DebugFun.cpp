//
// Created by roman on 10.07.2022.
//
#include "DebugFun.h"

void OutputMatrix(S21Matrix *_p) {
  for (int j = 0; j < _p->GetRows(); j++) {
    for (int i = 0; i < _p->GetCols(); i++) {
      if (i + 1 != _p->GetCols()) {
        std::cout << "|" << _p->GetEl(j, i) << "| ";
      } else {
        std::cout << "|" << _p->GetEl(j, i) << "|";
      }
    }
    if (j + 1!= _p->GetRows()) {
      std::cout << "\n";
    }
  }
}

void RandFill(S21Matrix &A, S21Matrix &B, int mode, unsigned int seed, double error, int type) {
  if (mode == SAME) {
    for (int j = 0; j < A.GetRows(); ++j) {
      for (int k = 0; k < A.GetCols(); ++k) {
        double r = rand_r(&seed);
        r = r / DIVIDER;
        A(j, k) = r;
        B(j, k) = r + error;
        if (type == INT) {
          A(j, k) = (int) A.GetEl(j, k);
          B(j, k) = (int) B.GetEl(j, k);
        }
      }
    }
  } else if (mode == DIFF) {
    for (int j = 0; j < A.GetRows(); ++j) {
      for (int k = 0; k < A.GetCols(); ++k) {
        double r = rand_r(&seed);
        r = r / DIVIDER;
        A(j, k) = r;
        double r1 = rand_r(&seed);
        r1 = r1 / DIVIDER * 10 + r;
        B(j, k) = r1;
        if (type == INT) {
          A(j, k) = (int) A.GetEl(j, k);
          B(j, k) = (int) B.GetEl(j, k);
        }
      }
    }
  } else if (mode == ONE) {
    for (int j = 0; j < A.GetRows(); ++j) {
      for (int k = 0; k < A.GetCols(); ++k) {
        double r = rand_r(&seed);
        r = r / DIVIDER;
        if (type == INT) {
          A(j, k) = (int)(r + (error * rand_r(&seed) / DIVIDER));
        } else if (type == FLT) {
          A(j, k) = (r + (error * rand_r(&seed) / DIVIDER));
        }
      }
    }
  }
}
