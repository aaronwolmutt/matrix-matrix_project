#include <Eigen/Core>
#include <Eigen/Dense>
#include <chrono>
#include <iostream>
#include <vector>
#include "head.h"

std::pair<double, double> time_matrix_multiplication(size_t n) {
  RandomMatrix *x = new RandomMatrix(n, n, 0, 5);
  RandomMatrix *y = new RandomMatrix(n, n, 0, 5);
  auto start = std::chrono::system_clock::now();
  x->generate() * y->generate();
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  delete x;
  delete y;
  std::vector<std::vector<int>> x1;
  std::vector<std::vector<int>> y1;
  for (int i = 0; i < n; i++) {
    std::vector<int> row;
    for (int j = 0; j < n; j++) {
      row.push_back(j);
    }
    x1.push_back(row);
    y1.push_back(row);
  }
  auto start1 = std::chrono::system_clock::now();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum += x1[i][j] * y1[i][j];
    }
  }
  auto end1 = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
  std::pair<double, double> pr(elapsed_seconds.count(),
                               elapsed_seconds1.count());
  return pr;
}

std::pair<double, double> time_vector_dot(size_t n) {
  RandomVector *x = new RandomVector(n, 0, 5);
  RandomVector *y = new RandomVector(n, 0, 5);
  auto start = std::chrono::system_clock::now();
  auto dotprod = x->generate().dot(y->generate());
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  delete x;
  delete y;
  std::vector<int> x1;
  std::vector<int> y1;
  for (int i = 0; i < n; i++) {
    x1.push_back(i);
    y1.push_back(i);
  }
  auto start1 = std::chrono::system_clock::now();
  int sum = 0;
  for (int i = 0; i < x1.size(); i++) {
    sum += x1[i] * y1[i];
  }
  auto end1 = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
  std::pair<double, double> pr(elapsed_seconds.count(),
                               elapsed_seconds1.count());
  return pr;
}

int main() {
  std::vector<size_t> v = {100, 1000, 10000};
  std::cout << "Matrix-matrix multiplication tests:" << std::endl;
  for (int i = 0; i < v.size(); i++) {
    std::cout << "size: " << v[i] << std::endl;
    std::cout << "    Eigen: " << time_matrix_multiplication(v[i]).first
              << std::endl;
    std::cout << "    std::vector: " << time_matrix_multiplication(v[i]).second
              << std::endl;
    std::cout << "\n" << std::endl;
  }
  std::vector<size_t> v1 = {100, 1000, 100000, 1000000};
  std::cout << "Vector dot product tests:" << std::endl;
  for (int i = 0; i < v1.size(); i++) {
    std::cout << "size: " << v1[i] << std::endl;
    std::cout << "    Eigen: " << time_vector_dot(v1[i]).first << std::endl;
    std::cout << "    std::vector: " << time_vector_dot(v1[i]).second
              << std::endl;
    std::cout << "\n" << std::endl;
  }

  return 0;
}