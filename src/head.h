#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <random>

class RandomMatrix {
 public:
  RandomMatrix(size_t& r, size_t& c, int l, int h)
      : row(r), column(c), low(l), high(h) {}

  ~RandomMatrix() {}
  Eigen::MatrixXf generate() {
    // initialize
    Eigen::MatrixXf mat(row, column);
    std::random_device seed;
    std::mt19937 random_no(seed());
    std::uniform_int_distribution<int> generate(low, high);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
        int rnum = generate(random_no);
        mat(i, j) = rnum;
      }
    }

    return mat;
  }

 private:
  size_t row;
  size_t column;
  int low;
  int high;
};

class RandomVector {
 public:
  RandomVector(size_t& s, int l, int h) : size(s), low(l), high(h) {}

  ~RandomVector() {}
  Eigen::VectorXf generate() {
    Eigen::VectorXf vec(size);
    std::random_device seed;
    std::mt19937 random_no(seed());
    std::uniform_int_distribution<int> generate(low, high);
    for (int i = 0; i < size; i++) {
      int rnum = generate(random_no);
      vec[i] = rnum;
    }
    return vec;
  }

 private:
  size_t size;
  int low;
  int high;
};
