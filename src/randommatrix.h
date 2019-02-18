#ifndef RANDOMMATRIX_H__
#define RANDOMMATRIX_H__
#include <Eigen/Core>
#include <Eigen/Dense>

#include <iostream>
#include <random>

namespace timings {
class RandomMatrix {
 public:
  RandomMatrix(size_t& row, size_t& col, int low, int high)
      : row(row), column(col), low(low), high(high) {}

  ~RandomMatrix() {}

  // Initialize a random eigen matrix with values in range low high
  Eigen::MatrixXf generate();

 private:
  size_t row;
  size_t column;
  int low;
  int high;
};
}
#endif