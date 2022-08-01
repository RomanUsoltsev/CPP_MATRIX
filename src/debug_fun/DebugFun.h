//
// Created by roman on 11.07.2022.
//

#ifndef SRC_DEBUG_FUN_DEBUGFUN_H_
#define SRC_DEBUG_FUN_DEBUGFUN_H_
#include "../main/CppMatrix.h"

void OutputMatrix(S21Matrix *_p);
#define DIVIDER 100000000
#define SAME 1
#define DIFF 2
#define ONE 3
#define INT 0
#define FLT 1
#define epsilon 1e-7
void RandFill(S21Matrix &A, S21Matrix &B, int mode, unsigned int seed, double error, int type);

#endif  //  SRC_DEBUG_FUN_DEBUGFUN_H_
