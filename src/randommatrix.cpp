#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <random>

#include "randommatrix.h"

namespace timings {
Eigen::MatrixXf RandomMatrix::generate() {
  Eigen::MatrixXf matrix(row, column);
  std::random_device seed;
  std::mt19937 random_no(seed());
  std::uniform_int_distribution<int> generate(low, high);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      int rnum = generate(random_no);
      matrix(i, j) = rnum;
    }
  }
  return matrix;
}
}