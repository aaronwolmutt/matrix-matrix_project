#ifndef TIMER_H__
#define TIMER_H__

#include <iostream>
#include <vector>

namespace timings {
struct Timer {
  // Time matrix matrix multiplication using the eigen library
  double time_matrix_multiplication_eigen(size_t n);

  // Time matrix matrix multiplication
  double time_matrix_multiplication_std(size_t n);

  // Time vector dot product using the eigen library
  double time_vector_dot_product_eigen(size_t n);

  // Time vector dot product using the standard library
  double time_vector_dot_product_std(size_t n);
};
}

#endif