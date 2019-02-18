#include "randommatrix.h"
#include "randomvector.h"
#include "timer.h"

#include <iostream>

int main(int argc, char *argv[]) {
  using namespace timings;
  Timer t = Timer();
  std::vector<size_t> v = {100, 1000, 10000};
  std::cout << "Matrix-matrix multiplication tests:" << std::endl;
  for (auto i : v) {
    std::cout << "size: " << i << std::endl;
    std::cout << "\t Eigen: " << t.time_matrix_multiplication_eigen(i)
              << std::endl;
    std::cout << "\t std::vector: " << t.time_matrix_multiplication_std(i)
              << std::endl;
    std::cout << "\n" << std::endl;
  }
  std::vector<size_t> v1 = {100, 1000, 100000, 1000000};
  std::cout << "Vector dot product tests:" << std::endl;
  for (auto x : v1) {
    std::cout << "size: " << x << std::endl;
    std::cout << "\t Eigen: " << t.time_vector_dot_product_eigen(x)
              << std::endl;
    std::cout << "\t std::vector: " << t.time_vector_dot_product_std(x)
              << std::endl;
    std::cout << "\n" << std::endl;
  }
  return 0;
}
