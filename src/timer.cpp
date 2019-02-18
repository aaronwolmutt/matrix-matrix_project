#include "timer.h"
#include "randommatrix.h"
#include "randomvector.h"

#include <Eigen/Core>
#include <Eigen/Dense>
#include <chrono>
#include <iostream>
#include <vector>

namespace timings {
double Timer::time_matrix_multiplication_eigen(size_t n) {
  RandomMatrix x = RandomMatrix(n, n, 0, 5);
  RandomMatrix y = RandomMatrix(n, n, 0, 5);
  auto start = std::chrono::system_clock::now();
  x.generate() * y.generate();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  return elapsed_seconds.count();
}

double Timer::time_matrix_multiplication_std(size_t n) {
  std::vector<std::vector<int>> x;
  std::vector<std::vector<int>> y;
  for (int i = 0; i < n; i++) {
    std::vector<int> row;
    for (int j = 0; j < n; j++) {
      row.push_back(j);
    }
    x.push_back(row);
    y.push_back(row);
  }
  auto start = std::chrono::system_clock::now();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum += x[i][j] * y[i][j];
    }
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  return elapsed_seconds.count();
}
double Timer::time_vector_dot_product_eigen(size_t n) {
  RandomVector x = RandomVector(n, 0, 5);
  RandomVector y = RandomVector(n, 0, 5);
  auto start = std::chrono::system_clock::now();
  auto dotprod = x.generate().dot(y.generate());
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  return elapsed_seconds.count();
}
double Timer::time_vector_dot_product_std(size_t n) {
  std::vector<int> x;
  std::vector<int> y;
  for (int i = 0; i < n; i++) {
    x.push_back(i);
    y.push_back(i);
  }
  auto start = std::chrono::system_clock::now();
  int sum = 0;
  for (int i = 0; i < x.size(); i++) {
    sum += x[i] * y[i];
  }
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  return elapsed_seconds.count();
}
}
