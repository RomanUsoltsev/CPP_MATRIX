//
// Created by roman on 10.07.2022.
//
#include <gtest/gtest.h>
#include "../main/CppMatrix.h"
#include "../debug_fun/DebugFun.h"


TEST(S21Matrix, constructor_1) {
  S21Matrix matr_1(5, 5);
  EXPECT_EQ(matr_1.GetRows(), 5);
  EXPECT_EQ(matr_1.GetCols(), 5);
}

TEST(S21Matrix, constructor_2) {
  S21Matrix matr_2;
  EXPECT_EQ(matr_2.GetRows(), 2);
  EXPECT_EQ(matr_2.GetCols(), 2);
}
//
TEST(S21Matrix, constructor_3) {
  S21Matrix matr_3(12, 12);
    RandFill(matr_3, matr_3, ONE, 100, 0, FLT);
  S21Matrix matr_3_1(matr_3);

  EXPECT_EQ(matr_3_1.GetRows(), 12);
  EXPECT_EQ(matr_3_1.GetCols(), 12);

  EXPECT_FLOAT_EQ(matr_3_1.GetEl(1, 1), matr_3.GetEl(1, 1));
  EXPECT_FLOAT_EQ(matr_3_1.GetEl(2, 2), matr_3.GetEl(2, 2));
  EXPECT_FLOAT_EQ(matr_3_1.GetEl(3, 3), matr_3.GetEl(3, 3));
  EXPECT_FLOAT_EQ(matr_3_1.GetEl(5, 8), matr_3.GetEl(5, 8));
  EXPECT_FLOAT_EQ(matr_3_1.GetEl(10, 9), matr_3.GetEl(10, 9));
}

TEST(S21Matrix, eq_matrix_1) {
  S21Matrix matr_eq_1(5, 5);
  S21Matrix matr_eq_2(5, 5);
    RandFill(matr_eq_1, matr_eq_2, SAME, 100, epsilon / 10, FLT);
  bool res = matr_eq_1 == matr_eq_2;
  EXPECT_EQ(res, true);
}

TEST(S21Matrix, eq_matrix_2) {
  S21Matrix matr_eq_3(5, 5);
  S21Matrix matr_eq_4(5, 5);
    RandFill(matr_eq_3, matr_eq_4, SAME, 200, epsilon * 10, FLT);
  bool res = matr_eq_3 == matr_eq_4;
  EXPECT_EQ(res, false);
}

TEST(S21Matrix, sum_matrix_1) {
  S21Matrix matr_sum_1(6, 6);
  S21Matrix matr_sum_2(6, 6);
    RandFill(matr_sum_1, matr_sum_1, ONE, 300, 0, FLT);
    RandFill(matr_sum_2, matr_sum_2, ONE, 305, 0, FLT);
  S21Matrix matr_sum_res_1 = matr_sum_1 + matr_sum_2;
  EXPECT_FLOAT_EQ(matr_sum_res_1.GetEl(0, 1), matr_sum_1.GetEl(0, 1) + matr_sum_2.GetEl(0, 1));
  EXPECT_FLOAT_EQ(matr_sum_res_1.GetEl(2, 3), matr_sum_1.GetEl(2, 3) + matr_sum_2.GetEl(2, 3));
  EXPECT_FLOAT_EQ(matr_sum_res_1.GetEl(4, 5), matr_sum_1.GetEl(4, 5) + matr_sum_2.GetEl(4, 5));
  EXPECT_FLOAT_EQ(matr_sum_res_1.GetEl(3, 3), matr_sum_1.GetEl(3, 3) + matr_sum_2.GetEl(3, 3));
}

TEST(S21Matrix, sub_matrix_1) {
  S21Matrix matr_sub_1(6, 6);
  S21Matrix matr_sub_2(6, 6);
    RandFill(matr_sub_1, matr_sub_1, ONE, 300, 0, FLT);
    RandFill(matr_sub_2, matr_sub_2, ONE, 305, 0, FLT);
  S21Matrix matr_sum_res_2 = matr_sub_1 - matr_sub_2;
  EXPECT_FLOAT_EQ(matr_sum_res_2.GetEl(0, 1), matr_sub_1.GetEl(0, 1) - matr_sub_2.GetEl(0, 1));
  EXPECT_FLOAT_EQ(matr_sum_res_2.GetEl(2, 3), matr_sub_1.GetEl(2, 3) - matr_sub_2.GetEl(2, 3));
  EXPECT_FLOAT_EQ(matr_sum_res_2.GetEl(4, 5), matr_sub_1.GetEl(4, 5) - matr_sub_2.GetEl(4, 5));
  EXPECT_FLOAT_EQ(matr_sum_res_2.GetEl(3, 3), matr_sub_1.GetEl(3, 3) - matr_sub_2.GetEl(3, 3));
}

TEST(S21Matrix, mul_number_1) {
  S21Matrix matr_n_1(6, 6);
    RandFill(matr_n_1, matr_n_1, ONE, 300, 0, FLT);
  double n = 324345.14673474;
  S21Matrix matr_n_res_1 = matr_n_1 * n;
  EXPECT_FLOAT_EQ(matr_n_res_1.GetEl(0, 1), matr_n_1.GetEl(0, 1) * n);
  EXPECT_FLOAT_EQ(matr_n_res_1.GetEl(2, 3), matr_n_1.GetEl(2, 3) * n);
  EXPECT_FLOAT_EQ(matr_n_res_1.GetEl(4, 5), matr_n_1.GetEl(4, 5) * n);
  EXPECT_FLOAT_EQ(matr_n_res_1.GetEl(3, 3), matr_n_1.GetEl(3, 3) * n);
}

TEST(S21Matrix, mul_matrix_1) {
  S21Matrix matr_m_1(2, 3);
  S21Matrix matr_m_2(3, 4);
    RandFill(matr_m_1, matr_m_1, ONE, 321, 0, FLT);
    RandFill(matr_m_2, matr_m_2, ONE, 123, 0, FLT);
  S21Matrix matr_m_res_1 = matr_m_1 * matr_m_2;
  double el_0_0 = matr_m_1.GetEl(0, 0) * matr_m_2.GetEl(0, 0) +
      matr_m_1.GetEl(0, 1) * matr_m_2.GetEl(1, 0) +
      matr_m_1.GetEl(0, 2) * matr_m_2.GetEl(2, 0);
  double el_0_1 = matr_m_1.GetEl(0, 0) * matr_m_2.GetEl(0, 1) +
      matr_m_1.GetEl(0, 1) * matr_m_2.GetEl(1, 1) +
      matr_m_1.GetEl(0, 2) * matr_m_2.GetEl(2, 1);
  double el_0_2 = matr_m_1.GetEl(0, 0) * matr_m_2.GetEl(0, 2) +
      matr_m_1.GetEl(0, 1) * matr_m_2.GetEl(1, 2) +
      matr_m_1.GetEl(0, 2) * matr_m_2.GetEl(2, 2);
  double el_0_3 = matr_m_1.GetEl(0, 0) * matr_m_2.GetEl(0, 3) +
      matr_m_1.GetEl(0, 1) * matr_m_2.GetEl(1, 3) +
      matr_m_1.GetEl(0, 2) * matr_m_2.GetEl(2, 3);

  EXPECT_FLOAT_EQ(matr_m_res_1.GetEl(0, 0), el_0_0);
  EXPECT_FLOAT_EQ(matr_m_res_1.GetEl(0, 1), el_0_1);
  EXPECT_FLOAT_EQ(matr_m_res_1.GetEl(0, 2), el_0_2);
  EXPECT_FLOAT_EQ(matr_m_res_1.GetEl(0, 3), el_0_3);
}

TEST(S21Matrix, transpose_1) {
  S21Matrix matr_tr_1(3, 3);
    RandFill(matr_tr_1, matr_tr_1, ONE, 78, 0, FLT);
  S21Matrix matr_tr_2 = matr_tr_1.Transpose();

  EXPECT_FLOAT_EQ(matr_tr_2.GetEl(0, 0), matr_tr_1.GetEl(0, 0));
  EXPECT_FLOAT_EQ(matr_tr_2.GetEl(0, 1), matr_tr_1.GetEl(1, 0));
  EXPECT_FLOAT_EQ(matr_tr_2.GetEl(0, 2), matr_tr_1.GetEl(2, 0));
  EXPECT_FLOAT_EQ(matr_tr_2.GetEl(1, 0), matr_tr_1.GetEl(0, 1));
  EXPECT_FLOAT_EQ(matr_tr_2.GetEl(1, 1), matr_tr_1.GetEl(1, 1));
  EXPECT_FLOAT_EQ(matr_tr_2.GetEl(1, 2), matr_tr_1.GetEl(2, 1));
  EXPECT_FLOAT_EQ(matr_tr_2.GetEl(2, 0), matr_tr_1.GetEl(0, 2));
  EXPECT_FLOAT_EQ(matr_tr_2.GetEl(2, 1), matr_tr_1.GetEl(1, 2));
  EXPECT_FLOAT_EQ(matr_tr_2.GetEl(2, 2), matr_tr_1.GetEl(2, 2));
}

TEST(S21Matrix, determinant_1) {
  S21Matrix matr_d_1(4, 4);
  matr_d_1(0, 0) = 13;
  matr_d_1(0, 1) = 22;
  matr_d_1(0, 2) = 35;
  matr_d_1(0, 3) = 6;
  matr_d_1(1, 0) = 84;
  matr_d_1(1, 1) = 59;
  matr_d_1(1, 2) = 6;
  matr_d_1(1, 3) = 7;
  matr_d_1(2, 0) = 25;
  matr_d_1(2, 1) = 1;
  matr_d_1(2, 2) = 5;
  matr_d_1(2, 3) = 6;
  matr_d_1(3, 0) = 15;
  matr_d_1(3, 1) = 67;
  matr_d_1(3, 2) = 6;
  matr_d_1(3, 3) = 5;
  double det_res = matr_d_1.Determinant();
  double det_check = -694161;

  EXPECT_FLOAT_EQ(det_res, det_check);
}

TEST(S21Matrix, calc_complements_1) {
  S21Matrix matr_c_1(4, 4);
  matr_c_1(0, 0) = 13;
  matr_c_1(0, 1) = 22;
  matr_c_1(0, 2) = 35;
  matr_c_1(0, 3) = 6;
  matr_c_1(1, 0) = 84;
  matr_c_1(1, 1) = 59;
  matr_c_1(1, 2) = 6;
  matr_c_1(1, 3) = 7;
  matr_c_1(2, 0) = 25;
  matr_c_1(2, 1) = 1;
  matr_c_1(2, 2) = 5;
  matr_c_1(2, 3) = 6;
  matr_c_1(3, 0) = 15;
  matr_c_1(3, 1) = 67;
  matr_c_1(3, 2) = 6;
  matr_c_1(3, 3) = 5;

  double e_l_0_0 = -570;
  double e_l_0_1 = 609;
  double e_l_0_2 = -23793;
  double e_l_0_3 = 22101;
  double e_l_1_0 = -11679;
  double e_l_1_1 = -918;
  double e_l_1_2 = -4029;
  double e_l_1_3 = 52173;
  double e_l_2_0 = 5538;
  double e_l_2_1 = 8697;
  double  e_l_2_2 = 19266;
  double e_l_2_3 = -156273;
  double e_l_3_0 = 10389;
  double e_l_3_1 = -9882;
  double e_l_3_2 = 11073;
  double e_l_3_3 =-50868;

  S21Matrix matr_c_2 = matr_c_1.CalcComplements();

  EXPECT_FLOAT_EQ(matr_c_2.GetEl(0, 0), e_l_0_0);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(0, 1), e_l_0_1);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(0, 2), e_l_0_2);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(0, 3), e_l_0_3);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(1, 0), e_l_1_0);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(1, 1), e_l_1_1);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(1, 2), e_l_1_2);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(1, 3), e_l_1_3);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(2, 0), e_l_2_0);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(2, 1), e_l_2_1);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(2, 2), e_l_2_2);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(2, 3), e_l_2_3);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(3, 0), e_l_3_0);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(3, 1), e_l_3_1);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(3, 2), e_l_3_2);
  EXPECT_FLOAT_EQ(matr_c_2.GetEl(3, 3), e_l_3_3);
}

TEST(S21Matrix, inverse_matrix_1) {
  S21Matrix matr_i_1(4, 4);
  matr_i_1(0, 0) = 13;
  matr_i_1(0, 1) = 22;
  matr_i_1(0, 2) = 35;
  matr_i_1(0, 3) = 6;
  matr_i_1(1, 0) = 84;
  matr_i_1(1, 1) = 59;
  matr_i_1(1, 2) = 6;
  matr_i_1(1, 3) = 7;
  matr_i_1(2, 0) = 25;
  matr_i_1(2, 1) = 1;
  matr_i_1(2, 2) = 5;
  matr_i_1(2, 3) = 6;
  matr_i_1(3, 0) = 15;
  matr_i_1(3, 1) = 67;
  matr_i_1(3, 2) = 6;
  matr_i_1(3, 3) = 5;

  double det_1 = matr_i_1.Determinant();

  double ee_l_0_0 = -570 / det_1;
  double ee_l_1_0 = 609 / det_1;
  double ee_l_2_0 = -23793 / det_1;
  double ee_l_3_0 = 22101 / det_1;
  double ee_l_0_1 = -11679 / det_1;
  double ee_l_1_1 = -918 / det_1;
  double ee_l_2_1 = -4029 / det_1;
  double ee_l_3_1 = 52173 / det_1;
  double ee_l_0_2 = 5538 / det_1;
  double ee_l_1_2 = 8697 / det_1;
  double ee_l_2_2 = 19266 / det_1;
  double ee_l_3_2 = -156273 / det_1;
  double ee_l_0_3 = 10389 / det_1;
  double ee_l_1_3 = -9882 / det_1;
  double ee_l_2_3 = 11073 / det_1;
  double ee_l_3_3 = -50868 / det_1;

  S21Matrix matr_i_2 = matr_i_1.InverseMatrix();

  EXPECT_FLOAT_EQ(matr_i_2.GetEl(0, 0), ee_l_0_0);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(0, 1), ee_l_0_1);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(0, 2), ee_l_0_2);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(0, 3), ee_l_0_3);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(1, 0), ee_l_1_0);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(1, 1), ee_l_1_1);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(1, 2), ee_l_1_2);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(1, 3), ee_l_1_3);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(2, 0), ee_l_2_0);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(2, 1), ee_l_2_1);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(2, 2), ee_l_2_2);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(2, 3), ee_l_2_3);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(3, 0), ee_l_3_0);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(3, 1), ee_l_3_1);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(3, 2), ee_l_3_2);
  EXPECT_FLOAT_EQ(matr_i_2.GetEl(3, 3), ee_l_3_3);
}

TEST(S21Matrix, accessors_1) {
  S21Matrix matr_a_1(8, 9);
  EXPECT_EQ(matr_a_1.GetRows(), 8);
  EXPECT_EQ(matr_a_1.GetCols(), 9);
}

TEST(S21Matrix, mutators_1) {
  S21Matrix matr_m_1(8, 9);
  matr_m_1.SetRowsCols(5, 6);
  EXPECT_EQ(matr_m_1.GetRows(), 5);
  EXPECT_EQ(matr_m_1.GetCols(), 6);
  matr_m_1.SetRowsCols(5, 6);
  EXPECT_EQ(matr_m_1.GetRows(), 5);
  EXPECT_EQ(matr_m_1.GetCols(), 6);
  matr_m_1.SetRowsCols(4, 6);
  EXPECT_EQ(matr_m_1.GetRows(), 4);
  EXPECT_EQ(matr_m_1.GetCols(), 6);
  matr_m_1.SetRowsCols(5, 6);
  EXPECT_EQ(matr_m_1.GetRows(), 5);
  EXPECT_EQ(matr_m_1.GetCols(), 6);
  matr_m_1.SetRowsCols(5, 7);
  EXPECT_EQ(matr_m_1.GetRows(), 5);
  EXPECT_EQ(matr_m_1.GetCols(), 7);
  matr_m_1.SetRowsCols(5, 4);
  EXPECT_EQ(matr_m_1.GetRows(), 5);
  EXPECT_EQ(matr_m_1.GetCols(), 4);
  matr_m_1.SetRowsCols(8, 9);
  EXPECT_EQ(matr_m_1.GetRows(), 8);
  EXPECT_EQ(matr_m_1.GetCols(), 9);
}

TEST(S21Matrix, operators_1) {
  S21Matrix matr_op_1(3, 3);
  S21Matrix matr_op_2(3, 3);
    RandFill(matr_op_1, matr_op_2, DIFF, 20, 0, FLT);

  S21Matrix matr_op_3;
  matr_op_3 = matr_op_1;
  matr_op_1 += matr_op_2;

  EXPECT_FLOAT_EQ(matr_op_1.GetEl(0, 0), matr_op_3.GetEl(0, 0) + matr_op_2.GetEl(0, 0));
  EXPECT_FLOAT_EQ(matr_op_1.GetEl(0, 1), matr_op_3.GetEl(0, 1) + matr_op_2.GetEl(0, 1));
  EXPECT_FLOAT_EQ(matr_op_1.GetEl(0, 2), matr_op_3.GetEl(0, 2) + matr_op_2.GetEl(0, 2));
  EXPECT_FLOAT_EQ(matr_op_1.GetEl(1, 0), matr_op_3.GetEl(1, 0) + matr_op_2.GetEl(1, 0));
  EXPECT_FLOAT_EQ(matr_op_1.GetEl(1, 1), matr_op_3.GetEl(1, 1) + matr_op_2.GetEl(1, 1));
  EXPECT_FLOAT_EQ(matr_op_1.GetEl(1, 2), matr_op_3.GetEl(1, 2) + matr_op_2.GetEl(1, 2));
  EXPECT_FLOAT_EQ(matr_op_1.GetEl(2, 0), matr_op_3.GetEl(2, 0) + matr_op_2.GetEl(2, 0));
  EXPECT_FLOAT_EQ(matr_op_1.GetEl(2, 1), matr_op_3.GetEl(2, 1) + matr_op_2.GetEl(2, 1));
  EXPECT_FLOAT_EQ(matr_op_1.GetEl(2, 2), matr_op_3.GetEl(2, 2) + matr_op_2.GetEl(2, 2));
}

TEST(S21Matrix, operators_2) {
  S21Matrix matr_op_11(3, 3);
  S21Matrix matr_op_22(3, 3);
    RandFill(matr_op_11, matr_op_22, DIFF, 25, 0, FLT);

  S21Matrix matr_op_33;
  matr_op_33 = matr_op_11;
  matr_op_11 -= matr_op_22;

  EXPECT_FLOAT_EQ(matr_op_11.GetEl(0, 0), matr_op_33.GetEl(0, 0) - matr_op_22.GetEl(0, 0));
  EXPECT_FLOAT_EQ(matr_op_11.GetEl(0, 1), matr_op_33.GetEl(0, 1) - matr_op_22.GetEl(0, 1));
  EXPECT_FLOAT_EQ(matr_op_11.GetEl(0, 2), matr_op_33.GetEl(0, 2) - matr_op_22.GetEl(0, 2));
  EXPECT_FLOAT_EQ(matr_op_11.GetEl(1, 0), matr_op_33.GetEl(1, 0) - matr_op_22.GetEl(1, 0));
  EXPECT_FLOAT_EQ(matr_op_11.GetEl(1, 1), matr_op_33.GetEl(1, 1) - matr_op_22.GetEl(1, 1));
  EXPECT_FLOAT_EQ(matr_op_11.GetEl(1, 2), matr_op_33.GetEl(1, 2) - matr_op_22.GetEl(1, 2));
  EXPECT_FLOAT_EQ(matr_op_11.GetEl(2, 0), matr_op_33.GetEl(2, 0) - matr_op_22.GetEl(2, 0));
  EXPECT_FLOAT_EQ(matr_op_11.GetEl(2, 1), matr_op_33.GetEl(2, 1) - matr_op_22.GetEl(2, 1));
  EXPECT_FLOAT_EQ(matr_op_11.GetEl(2, 2), matr_op_33.GetEl(2, 2) - matr_op_22.GetEl(2, 2));
}

TEST(S21Matrix, operators_3) {
  S21Matrix matr_op_31(2, 3);
  S21Matrix matr_op_32(3, 4);
    RandFill(matr_op_31, matr_op_31, ONE, 321, 0, FLT);
    RandFill(matr_op_32, matr_op_32, ONE, 123, 0, FLT);

  S21Matrix matr_op_34;
  matr_op_34 = matr_op_31;
  matr_op_31 *= matr_op_32;

  double op_el_0_0 = matr_op_34.GetEl(0, 0) * matr_op_32.GetEl(0, 0) +
      matr_op_34.GetEl(0, 1) * matr_op_32.GetEl(1, 0) +
      matr_op_34.GetEl(0, 2) * matr_op_32.GetEl(2, 0);
  double op_el_0_1 = matr_op_34.GetEl(0, 0) * matr_op_32.GetEl(0, 1) +
      matr_op_34.GetEl(0, 1) * matr_op_32.GetEl(1, 1) +
      matr_op_34.GetEl(0, 2) * matr_op_32.GetEl(2, 1);
  double op_el_0_2 = matr_op_34.GetEl(0, 0) * matr_op_32.GetEl(0, 2) +
      matr_op_34.GetEl(0, 1) * matr_op_32.GetEl(1, 2) +
      matr_op_34.GetEl(0, 2) * matr_op_32.GetEl(2, 2);
  double op_el_0_3 = matr_op_34.GetEl(0, 0) * matr_op_32.GetEl(0, 3) +
      matr_op_34.GetEl(0, 1) * matr_op_32.GetEl(1, 3) +
      matr_op_34.GetEl(0, 2) * matr_op_32.GetEl(2, 3);

  EXPECT_FLOAT_EQ(matr_op_31.GetEl(0, 0), op_el_0_0);
  EXPECT_FLOAT_EQ(matr_op_31.GetEl(0, 1), op_el_0_1);
  EXPECT_FLOAT_EQ(matr_op_31.GetEl(0, 2), op_el_0_2);
  EXPECT_FLOAT_EQ(matr_op_31.GetEl(0, 3), op_el_0_3);
}

TEST(S21Matrix, constructor_4) {
  S21Matrix m1(3, 3);
  S21Matrix m_res(m1);
  S21Matrix m2(std::move(m1));
  ASSERT_TRUE(m_res.EqMatrix(m2));
}

TEST(S21Matrix, operator_mul_1) {
  S21Matrix m1(10, 10);
    RandFill(m1, m1, ONE, 798, 0, FLT);
  int num = 5;
  S21Matrix m3 = m1 * num;
  S21Matrix m44(m1);
  for (int i = 1; i < num; ++i) {
     m44 += m1;
  }
  ASSERT_TRUE(m3.EqMatrix(m44));
}

TEST(S21Matrix, operator_mul_2) {
  S21Matrix m1(10, 10);
  S21Matrix m2(10, 10);
    RandFill(m1, m2, ONE, 700, 0, FLT);
  int num = 5;
  S21Matrix m3 = m1 * num;
  S21Matrix m4 = num * m1;
  ASSERT_TRUE(m3.EqMatrix(m4));
}

TEST(S21Matrix, operator_mul_3) {
  S21Matrix m1(10, 10);
    RandFill(m1, m1, ONE, 700, 0, FLT);
  S21Matrix m2 = 2 * m1;
  m1 *= 2;
  ASSERT_TRUE(m1.EqMatrix(m2));
}


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
