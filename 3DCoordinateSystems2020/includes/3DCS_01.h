#include <iostream>
#include <vector>
using std::size_t;
using std::vector;

namespace CS3D {

struct point3d {
  float x;
  float y;
  float z;
};

enum class rotationAxis { xaxis = 0, yaxis, zaxis };

point3d rotation(CS3D::rotationAxis axis, const float rotationAngle_deg);

template <typename elemtype>
class Vector {
 public:
  explicit Vector(const std::size_t size_vect);
  explicit Vector(const vector<elemtype>& init_vect);
  Vector<elemtype>& operator+(const Vector<elemtype>& other);
  Vector<elemtype>& operator*(const elemtype scale_factor);

  std::size_t Size() const;
  void Print() const;

 private:
  std::vector<elemtype> elements;
};

template <typename elemtype>
Vector<elemtype>::Vector(const std::size_t size_vect)
    : elements(size_vect, 0) {}

template <typename elemtype>
Vector<elemtype>::Vector(const vector<elemtype>& init_vect)
    : elements(init_vect) {}

template <typename elemtype>
Vector<elemtype>& Vector<elemtype>::operator+(const Vector<elemtype>& other) {
  for (std::size_t i = 0; i < this->Size(); ++i) {
    elements[i] += other.elements[i];
  }
  return *this;
}

template <typename elemtype>
void Vector<elemtype>::Print() const {
  std::cout << "<";
  for (typename vector<elemtype>::const_iterator i = elements.begin();
       i != elements.end(); ++i) {
    std::cout << *i << ",";
  }
  std::cout << ">";
}

template <typename elemtype>
std::size_t Vector<elemtype>::Size() const {
  return elements.size();
}

template <typename elemtype>
Vector<elemtype>& Vector<elemtype>::operator*(const elemtype scale_factor) {
  for (typename std::vector<elemtype>::iterator itr = elements.begin();
       itr != elements.end(); ++itr) {
    *itr = *itr * scale_factor;
  }
}

// Matrix template
template <typename elemtype>
class Matrix {
 public:
  Matrix(const size_t row, const size_t column);

  explicit Matrix(const std::vector<vector<elemtype> >& v);

  Matrix<elemtype>& operator+(const Matrix<elemtype>& other);

  Matrix<elemtype>& operator*(const Matrix<elemtype>& other);

  ~Matrix();

 private:
  std::vector<std::vector<elemtype> > v;
  size_t col_size;
  size_t row_size;
};

}  // namespace CS3D
