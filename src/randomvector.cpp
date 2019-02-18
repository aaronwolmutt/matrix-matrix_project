#include "randomvector.h"

#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <random>

namespace timings {
Eigen::VectorXf RandomVector::generate() {
  Eigen::VectorXf vector(size);
  std::random_device seed;
  std::mt19937 random_no(seed());
  std::uniform_int_distribution<int> generate(low, high);
  for (int i = 0; i < size; i++) {
    int rnum = generate(random_no);
    vector[i] = rnum;
  }
  return vector;
}
}
