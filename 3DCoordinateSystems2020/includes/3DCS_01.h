#include <iostream>
#include <vector>
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

}  // namespace CS3D
