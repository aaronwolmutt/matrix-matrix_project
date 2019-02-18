#ifndef RANDOMVECTOR_H__
#define RANDOMVECTOR_H__

#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>

namespace timings {
class RandomVector {
 public:
  RandomVector(size_t& size, int low, int high)
      : size(size), low(low), high(high) {}

  ~RandomVector() {}

  // Initalize a random eigen vector with values in range low, high
  Eigen::VectorXf generate();

 private:
  size_t size;
  int low;
  int high;
};
}
#endif